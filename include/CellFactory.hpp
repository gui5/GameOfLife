#ifndef __CELLFACTORY__
#define __CELLFACTORY__

#include "Cell.hpp"
#include "Seed.hpp"

#include <cstring>
#include <vector>

struct CellFactory {
  template <unsigned width, unsigned height>
  static std::vector<Cell> initialize(Seed &seed) {

    std::vector<Cell> cells;
    char sd[width][height];
    memset(&sd, 0, sizeof(sd));
    if (seed.generate_seed(sd)) {
      for (unsigned i = 0; i < width; i++) {
        for (unsigned j = 0; j < height; j++) {
          cells.emplace_back(i, j, state_cast(sd[i][j]));
        }
      }
    }
    return std::move(cells);
  }

  CellFactory(const CellFactory &) = delete;
  CellFactory(CellFactory &&) = delete;

private:
  CellFactory(void) = default;
  ~CellFactory(void) = default;
};

#endif