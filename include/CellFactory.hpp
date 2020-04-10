#ifndef __CELLFACTORY__
#define __CELLFACTORY__

#include "Cell.hpp"
#include "Seed.hpp"

#include <array>
#include <cstring>

struct CellFactory {

  template <int width, int height>
  static std::array<std::array<Cell*, height>, width> initialize(Seed &&seed) {

    std::array<std::array<Cell*, height>, width> cells;
    char sd[width][height];
    memset(&sd, 0, sizeof(sd));
    if (seed.generate_seed(sd)) {
      for (unsigned i = 0; i < width; i++) {
        for (unsigned j = 0; j < height; j++) {
          cells[i][j] = new Cell(CellPosition(i, j), state_cast(sd[i][j]));
        }
      }
    }
    return cells;
  }

  CellFactory(const CellFactory &) = delete;
  CellFactory(CellFactory &&) = delete;

private:
  CellFactory(void) = default;
  ~CellFactory(void) = default;
};

#endif