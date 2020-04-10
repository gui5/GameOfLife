#ifndef __CELL__
#define __CELL__

#include "CellState.hpp"
#include "MatrixDimentions.hpp"
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

template <int axis_size> constexpr int sanitize_coordinate(int input_pos) {
  if (input_pos < 0) {
    return axis_size - 1;
  }
  if (input_pos >= axis_size) {
    return 0;
  }

  return input_pos;
}

struct CellPosition {
  int x, y;

  CellPosition(int x = 0, int y = 0) : x(x), y(y) {}

  // bool is_neighbor(const CellPosition &pos) const {
  //   for (const auto &np : npos) {
  //     if (pos == np)
  //       return true;
  //   }
  //   return false;
  // }

  bool operator==(const CellPosition &other) const {
    return other.x == x && other.y == y;
  }
  bool operator==(const CellPosition &other) {
    return other.x == x && other.y == y;
  }
};

struct Cell {
  Cell(CellPosition &&pos, CellState state)
      : pos(std::move(pos)), state(state),
        npos{CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x - 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y - 1)),
             CellPosition(pos.x,
                          sanitize_coordinate<matrix::y_lenght>(pos.y - 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x + 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y - 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x + 1),
                          pos.y),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x + 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y + 1)),
             CellPosition(pos.x,
                          sanitize_coordinate<matrix::y_lenght>(pos.y + 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x - 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y + 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x - 1),
                          pos.y)} {}

  Cell(CellPosition &pos, CellState state)
      : pos(pos), state(state),
        npos{CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x - 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y - 1)),
             CellPosition(pos.x,
                          sanitize_coordinate<matrix::y_lenght>(pos.y - 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x + 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y - 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x + 1),
                          pos.y),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x + 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y + 1)),
             CellPosition(pos.x,
                          sanitize_coordinate<matrix::y_lenght>(pos.y + 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x - 1),
                          sanitize_coordinate<matrix::y_lenght>(pos.y + 1)),
             CellPosition(sanitize_coordinate<matrix::x_lenght>(pos.x - 1),
                          pos.y)} {}

  Cell(void) {}

  CellPosition pos;
  CellState state;
  std::array<CellPosition, 8> npos;

  bool operator==(const Cell &other) const { return pos == other.pos; }
  bool operator==(const Cell &other) { return pos == other.pos; }

  // bool is_neighbor(Cell &cell) { return cell.pos.is_neighbor(pos); }
};

#endif