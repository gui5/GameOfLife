
#include <Seed.hpp>

int main(int ac, char **av) {
  auto ss = Seed();

  int live_count = 0;
  int dead_count = 0;

  CellStateArray<> states;
  ss.generate_seed(states);
  for (const auto &rows : states) {
    for (const auto &state : rows) {
      if (state == CellState::alive) {
        ++live_count;
      }
      if (state == CellState::dead) {
        ++dead_count;
      }
    }
  }
  printf("Alive Cells: %d\nDead Cells: %d\n", live_count, dead_count);
  if (dead_count > 0 && live_count > 0)
    return 0;
  return 1;
}