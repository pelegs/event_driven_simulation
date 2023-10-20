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
  vec p1(0, 0);
  vec p2(1000, 1000);
  double radius = 30.0;
  Wall wall(p1, p2, sf::Color::White);
  Ball ball(vec(250., 300.), 5. * X_, 1.0, radius, sf::Color::Green);
  vec mouse_pos, intersection;
  vec diff = radius * vec(1., 1.);

  // Intersection point
  sf::CircleShape intersection_shape(5);
  intersection_shape.setFillColor(sf::Color::Red);
  sf::Vector2f intersection_vertex;

  sf::RenderWindow window(sf::VideoMode(500, 500), "SFML graphics test");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    mouse_pos = Vector2i_to_vec2(sf::Mouse::getPosition(window));
    ball.set_pos(mouse_pos - diff);
    intersection = vel_wall_intersection_pt(ball, wall);

    window.clear();
    if (intersection != INF_VEC) {
      // std::cout << glm::to_string(intersection) << std::endl;
      intersection_vertex = glm_to_sfml_vec2(intersection+diff*0.5);
      intersection_shape.setPosition(intersection_vertex);
      window.draw(intersection_shape);
    }
    window.draw(wall.get_vertices(), 2, sf::Lines);
    window.draw(ball.get_shape());
    window.display();
  }
  return 0;
}
