#ifndef __GENERATIONMACHINE__
#define __GENERSTIONMACHINE__

#include "Cell.hpp"
#include "Seed.hpp"

#include <SFML/Graphics.hpp>
#include <array>
#include <atomic>
#include <chrono>
#include <cstring>
#include <thread>
#include <vector>

class GenerationMachine {
public:
  GenerationMachine(PCellArray<matrix::x_lenght, matrix::y_lenght> &cells)
      : _run(true), _cells(cells) {}
  ~GenerationMachine() { stop(); }

  void start(void) {
    _th = std::thread(&GenerationMachine::generation_loop, this);
  }

  void stop(void) {
    _run = false;
    _th.join();
  }

private:
  std::atomic<bool> _run;
  std::thread _th;
  RamdomCellSateArray<matrix::x_lenght, matrix::y_lenght> _seed;
  PCellArray<matrix::x_lenght, matrix::y_lenght> &_cells;

  void generation_loop(void) {
    _run = true;
    while (_run) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      Seed().generate_seed<matrix::x_lenght, matrix::y_lenght>(_seed);
      for (int i = 0; i < matrix::x_lenght; i++) {
        for (int j = 0; j < matrix::y_lenght; j++) {
          _cells[i][j]->set_state(_seed[i][j]);
        }
      }
    }
  }
};
#endif