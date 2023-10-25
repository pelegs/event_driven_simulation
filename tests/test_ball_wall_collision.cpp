// ------------------------------- //
// THIS IS A VERY SILLY QUICK TEST //
// ------------------------------- //

#include "balls.hpp"
#include "graphics.hpp"
#include "maths.hpp"
#include "physics.hpp"
#include "walls.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  double width = 1500., height = 2000., diff = 5.;

  // Create walls
  Wall wall_h1(vec(diff, diff), Y_, sf::Color::Red, width);
  Wall wall_v1(vec(diff, diff), X_, sf::Color::Green, height);
  Wall wall_h2(vec(width-diff, height-diff), Y_, sf::Color::Blue, width);
  Wall wall_v2(vec(width-diff, height-diff), X_, sf::Color::White, height);
  std::vector<Wall *> walls = {&wall_h1, &wall_v1, &wall_h2, &wall_v2};

  sf::RenderWindow window(sf::VideoMode(width, height), "SFML graphics test");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    for (auto wall : walls)
      window.draw(wall->get_line_shape(), 2, sf::Lines);
    window.display();
  }
  return 0;
}
