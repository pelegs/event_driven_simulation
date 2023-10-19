#include "balls.hpp"
#include "walls.hpp"
#include "graphics.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  vec p1(200, 200);
  vec p2(300, 400);
  Wall wall(p1, p2, sf::Color::Red);
  Ball ball(vec(250., 300.), ZERO_VEC, 1.0, 30.0, sf::Color::Green);

  sf::RenderWindow window(sf::VideoMode(700, 700), "SFML graphics test");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    } 
    window.draw(wall.get_vertices(), 2, sf::Lines);
    window.draw(ball.get_shape());
    window.display();
  }
  return 0;
}
