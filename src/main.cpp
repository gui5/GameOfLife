#include <SFML/Graphics.hpp>

#include <CellFactory.hpp>
#include <fps.hpp>

int main(int argc, char **argv) {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Game of Life");
  window.setVerticalSyncEnabled(
      true); // call it once, after creating the window

  Fps fps;
  sf::Text text;
  sf::Font font;
  font.loadFromFile("../assets/fonts/VCR_OSD_MONO_1.001.ttf");
  text.setFillColor(sf::Color::White);
  text.setFont(font);
  text.setCharacterSize(32);

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
    window.draw(text);
    window.display();
  }

  return 0;
}