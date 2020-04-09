#ifndef __CELLSTATE__
#define __CELLSTATE__

enum class CellState { dead, alive };

constexpr CellState state_cast(char state) {
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
}

enum class Trigger { live, die };

#endif