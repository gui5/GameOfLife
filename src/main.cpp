#include <CellFactory.hpp>
#include <GenerationMachine.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char **argv) noexcept {

  sf::RenderWindow window(
      sf::VideoMode(window_resolution::width, window_resolution::height),
      "Game of Life");

  window.setVerticalSyncEnabled(true);

  auto cells = CellFactory::initialize(Seed());
  GenerationMachine gm(cells);

  gm.start();

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::Closed:
        gm.stop();
        gm.join();
        window.close();
        break;

      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
          gm.reset();
          printf("State reset!\n");
        }
        break;

      default:
        break;
      }
    }

    window.clear();

    for (const auto &wc : cells) {
      for (const auto &hc : wc) {
        window.draw(hc->pixel);
      }
    }
    window.display();
  }

  return 0;
}