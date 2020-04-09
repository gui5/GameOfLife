#ifndef __CELL__
#define __CELL__

#include "CellState.hpp"

struct Cell {
  Cell(unsigned pos_x, unsigned pos_y, CellState state)
      : pos_x(pos_x), pos_y(pos_y), state(state) {}

  unsigned pos_x;
  unsigned pos_y;
  CellState state;

  //Cell *_neighbours[8];
};

#endif