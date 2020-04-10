#ifndef __SEED__
#define __SEED__

#include <array>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <chrono>
#include <sys/time.h>

struct Seed {
  template <unsigned width = 0, unsigned height = 0>
  bool generate_seed(char (&seed)[width][height]) {
    for (int w = 0; w < width; w++) {
      for (int h = 0; h < height; h++) {
        {
          struct timespec ts;
          clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
          srand(ts.tv_nsec);
          seed[w][h] = rand() % 2;
        }
      }
    }
    return true;
  }
};

#endif