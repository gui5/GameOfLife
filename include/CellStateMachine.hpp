#ifndef __CELLSTATEMACHINE__
#define __CELLSTATEMACHINE__

#include "CellState.hpp"
#include <map>
#include <vector>

struct CellStateMachine {
  std::map<CellState, std::vector<std::pair<Trigger, CellState>>> rules;

  CellStateMachine() {
    rules[CellState::alive] = {{Trigger::die, CellState::dead},
                               {Trigger::live, CellState::alive}};
  }
};

#endif