#ifndef __GENERATIONMACHINE__
#define __GENERSTIONMACHINE__

#include "Cell.hpp"
#include "Seed.hpp"

#include <SFML/Graphics.hpp>
#include <atomic>
#include <thread>

class GenerationMachine {
public:
  GenerationMachine(PCellArray<matrix::x_lenght, matrix::y_lenght> &cells)
      : _run(true), _cells(cells) {}
  ~GenerationMachine() {
    stop();
    join();
  }

  void start(void) {
    _th = std::thread(&GenerationMachine::generation_loop, this);
  }

  void stop(void) { _run = false; }

  void join(void) {
    if (_th.joinable())
      _th.join();
  }

private:
  std::atomic<bool> _run;
  std::thread _th;
  CellStateArray<matrix::x_lenght, matrix::y_lenght> _nex_gen_state;
  PCellArray<matrix::x_lenght, matrix::y_lenght> &_cells;

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
    while (_run) {
      std::this_thread::sleep_for(std::chrono::milliseconds(120));
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