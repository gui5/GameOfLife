#ifndef __SEED__
#define __SEED__

#include <CellState.hpp>
#include <sys/time.h>

struct Seed {

  bool generate_seed(CellStateArray<> &rcsa) {
    struct timespec ts;
    for (int w = 0; w < matrix::x_lenght; w++) {
      for (int h = 0; h < matrix::y_lenght; h++) {
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