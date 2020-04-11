#ifndef __CELLSTATE__
#define __CELLSTATE__

#include "MatrixDimentions.hpp"

#include <SFML/Graphics.hpp>
#include <array>

enum class CellState { dead, alive };

template <int width = matrix::x_lenght, int height = matrix::y_lenght>
using CellStateArray = std::array<std::array<CellState, height>, width>;

constexpr CellState state_cast(int state) {
  switch (state) {
  case 0:
    return CellState::dead;
    break;
  case 1:
    return CellState::alive;
    break;
  default:
    break;
  }
  return CellState::dead;
};

sf::Color color_state(CellState state) {
  switch (state) {
  case CellState::alive:
    return sf::Color::Black;
    break;
  case CellState::dead:
    return sf::Color::White;
  default:
    break;
  }
  return sf::Color::Yellow;
}

enum class Trigger { live, die };

#endif