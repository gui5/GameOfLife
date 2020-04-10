#include <CellFactory.hpp>
#include <GenerationMachine.hpp>
#include <MatrixDimentions.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {

  sf::RenderWindow window(
      sf::VideoMode(window_resolution::width, window_resolution::height),
      "Game of Life");

  window.setVerticalSyncEnabled(true);

  auto cells =
      CellFactory::initialize<matrix::x_lenght, matrix::y_lenght>(Seed());
  GenerationMachine gm(cells);

  gm.start();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        gm.stop();
        window.close();
      }
    }

    window.clear();

    for (auto &wc : cells) {
      for (auto &hc : wc) {
        window.draw(hc->pixel);
      }
    }
    window.display();
  }

  return 0;
}