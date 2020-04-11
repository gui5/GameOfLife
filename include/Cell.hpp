#ifndef __CELL__
#define __CELL__

#include "CellState.hpp"
#include "MatrixDimentions.hpp"

#include <SFML/Graphics.hpp>

struct Cell;
using PCell = std::unique_ptr<Cell>;

template <int width = matrix::x_lenght, int height = matrix::y_lenght>
using PCellArray = std::array<std::array<PCell, height>, width>;

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
                          pos.y)} {
    pixel.setSize(sf::Vector2f(pixel_size::side, pixel_size::side));
    pixel.setPosition(pos.x * pixel_size::side, pos.y * pixel_size::side);
    pixel.setFillColor(color_state(state));
  }

  Cell(void) {}

  CellPosition pos;
  CellState state;
  std::array<CellPosition, 8> npos;
  sf::RectangleShape pixel;

  bool operator==(const Cell &other) const { return pos == other.pos; }
  bool operator==(const Cell &other) { return pos == other.pos; }

  void set_state(CellState st) {
    state = st;
    pixel.setFillColor(color_state(state));
  }

  int get_neighbours_sum(PCellArray<> &cells) {
    int sum = state == CellState::alive ? 1 : 0;
    for (const auto &nb : npos) {
      sum += (cells[nb.x][nb.y])->state == CellState::alive ? 1 : 0;
    }
    return sum;
  }
};

#endif