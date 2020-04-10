#include <CellFactory.hpp>
#include <MatrixDimentions.hpp>
#include <SFML/Graphics.hpp>
#include <fps.hpp>

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");
  window.setVerticalSyncEnabled(
      true); // call it once, after creating the window

  sf::Vector2f px_sz(pixel_size::side, pixel_size::side);
  sf::RectangleShape px(px_sz);
  Fps fps;
  sf::Text text;
  sf::Font font;
  font.loadFromFile("../assets/fonts/VCR_OSD_MONO_1.001.ttf");
  text.setFillColor(sf::Color::White);
  text.setFont(font);
  text.setCharacterSize(32);

  auto cells =
      CellFactory::initialize<matrix::x_lenght, matrix::y_lenght>(Seed());

  std::vector<sf::RectangleShape> pixels;
  for (int i = 0; i < matrix::x_lenght; i++) {
    for (int j = 0; j < matrix::y_lenght; j++) {
      pixels.emplace_back(px_sz);
      pixels.back().setPosition(i * pixel_size::side, j * pixel_size::side);
      auto cell = cells.at(i).at(j);

      pixels.back().setFillColor(cell->state == CellState::alive
                                     ? sf::Color::White
                                     : sf::Color::Black);
    }
  }

  char c[16];
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    fps.update();
    sprintf(c, "%d FPS", fps.get_fps());
    text.setString(c);
    for (auto &px : pixels) {
      window.draw(px);
    }
    window.display();
  }

  return 0;
}