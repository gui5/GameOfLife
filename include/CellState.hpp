#ifndef __CELLSTATE__
#define __CELLSTATE__

#include <SFML/Graphics.hpp>

enum class CellState { dead, alive };

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
    return sf::Color::White;
    break;
  case CellState::dead:
    return sf::Color::Black;
  default:
    break;
  }
  return sf::Color::Yellow;
}



enum class Trigger { live, die };

#endif