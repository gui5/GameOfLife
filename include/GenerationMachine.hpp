#ifndef __GENERATIONMACHINE__
#define __GENERSTIONMACHINE__

#include "Cell.hpp"
#include "Seed.hpp"

#include <SFML/Graphics.hpp>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

static constexpr int generation_speed_ms = 167 ;

class GenerationMachine {
public:
  GenerationMachine(PCellArray<matrix::x_lenght, matrix::y_lenght> &cells)
      : _run(true), _reset(false), _cells(cells) {}
  ~GenerationMachine() {
    stop();
    join();
  }

  void start(void) {
    _th = std::thread(&GenerationMachine::generation_loop, this);
  }

  void stop(void) {
    _run = false;
    _cvar_loop_control.notify_all();
  }

  void join(void) {
    if (_th.joinable())
      _th.join();
  }

  void reset(void) {
    _reset = true;
    _cvar_loop_control.notify_all();
  }

private:
  std::atomic<bool> _run;
  std::atomic<bool> _reset;
  std::thread _th;
  CellStateArray<> _nex_gen_state;
  PCellArray<> &_cells;
  std::mutex _mtx;
  std::condition_variable _cvar_loop_control;

  void randomize(void) {
    CellStateArray<> random_state;
    Seed().generate_seed(random_state);
    for (int i = 0; i < matrix::x_lenght; i++) {
      for (int j = 0; j < matrix::y_lenght; j++) {
        _cells[i][j]->set_state(random_state[i][j]);
      }
    }
  }

  void compute_generation(PCellArray<> &cells, CellStateArray<> &next_states) {
    for (int i = 0; i < matrix::x_lenght; i++)
      for (int j = 0; j < matrix::y_lenght; j++) {
        switch (cells[i][j]->get_neighbours_sum(cells)) {
        case 3:
          next_states[i][j] = CellState::alive;
          break;
        case 4:
          next_states[i][j] = cells[i][j]->state;
          break;
        default:
          next_states[i][j] = CellState::dead;
          break;
        }
      }
  }

  void generation_loop(void) {
    _run = true;
    std::unique_lock<std::mutex> lck(_mtx);

    while (_run) {

      _cvar_loop_control.wait_for(
          lck, std::chrono::milliseconds(generation_speed_ms));

      if (_reset) {
        randomize();
        _reset = false;
        continue;
      }

      compute_generation(_cells, _nex_gen_state);

      for (int i = 0; i < matrix::x_lenght; i++) {
        for (int j = 0; j < matrix::y_lenght; j++) {
          _cells[i][j]->set_state(_nex_gen_state[i][j]);
        }
      }
    }
  }
};
#endif