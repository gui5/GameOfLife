#ifndef __SEED__
#define __SEED__

#include <CellState.hpp>
#include <array>
#include <chrono>
#include <cstdlib>
#include <sys/time.h>
#include <thread>
#include <time.h>

template <int width, int height>
using RamdomCellSateArray = std::array<std::array<CellState, height>, width>;

struct Seed {

  template <int width = 0, int height = 0>
  bool generate_seed(RamdomCellSateArray<width, height> &rcsa) {
    struct timespec ts;
    for (int w = 0; w < width; w++) {
      for (int h = 0; h < height; h++) {
        clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
        srand(ts.tv_nsec);
        int s = rand() % 2;
        rcsa[w][h] = state_cast(s);
      }
    }
    return true;
  }
};

#endif