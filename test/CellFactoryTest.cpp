#include <CellFactory.hpp>

int main(int ac, char **av) {
  auto cells = CellFactory::initialize<matrix::x_lenght, matrix::y_lenght>(Seed());

  return 0;
}