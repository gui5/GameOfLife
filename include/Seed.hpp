#ifndef __SEED__
#define __SEED__

#include <array>
#include <cstdlib>
#include <time.h>

struct Seed {

  static Seed &get(void) noexcept {
    static Seed instance;
    return instance;
  }

  template <unsigned width = 0, unsigned height = 0>
  bool generate_seed(char (&seed)[width][height]) {
    for (unsigned w = 0; w < width; w++) {
      for (unsigned h = 0; h < height; h++) {
        seed[w][h] = rand() % 2;
      }
    }
    return true;
  }

private:
  Seed(void) = default;
  ~Seed(void) = default;
};

#endif