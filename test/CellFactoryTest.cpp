#include <CellFactory.hpp>

int main(int ac, char **av) {

  auto cells = CellFactory::initialize(Seed());
  return cells.empty();
}