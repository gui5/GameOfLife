#ifndef __CELLFACTORY__
#define __CELLFACTORY__

#include "Cell.hpp"
#include "Seed.hpp"


struct CellFactory {

  static PCellArray<> initialize(Seed &&seed) {
    PCellArray<> cells;
    CellStateArray<> sd;
    if (seed.generate_seed(sd)) {
      for (unsigned i = 0; i < matrix::x_lenght; i++) {
        for (unsigned j = 0; j < matrix::y_lenght; j++) {
          cells[i][j] = std::make_unique<Cell>(CellPosition(i, j), sd[i][j]);
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