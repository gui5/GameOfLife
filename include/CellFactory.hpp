#ifndef __CELLFACTORY__
#define __CELLFACTORY__

#include "Cell.hpp"
#include "Seed.hpp"

#include <array>
#include <cstring>
#include <memory>

struct CellFactory {

  template <int width, int height>
  static PCellArray<width, height> initialize(Seed &&seed) {
    PCellArray<width, height> cells;
    RamdomCellSateArray<width, height> sd;
    // memset(&sd, 0, sizeof(sd));
    if (seed.generate_seed<width, height>(sd)) {
      for (unsigned i = 0; i < width; i++) {
        for (unsigned j = 0; j < height; j++) {
          cells[i][j] = std::make_unique<Cell>(CellPosition(i, j), sd[i][j]);
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