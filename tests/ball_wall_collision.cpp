// ------------------------------------------ //
// THIS IS A VERY SILLY QUICK TEST            //
// (testing collision between ball and walls) //
// ------------------------------------------ //

#include "balls.hpp"
#include "graphics.hpp"
#include "maths.hpp"
#include "physics.hpp"
#include "walls.hpp"
#include <SFML/Graphics/Shape.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
  // Parameters
  double width = 1500., height = 1500., diff = 5.;
  vec SCREEN_CENTER(width/2., height/2.);
  double dt = 1.;

  // Create ball
  vec ball_pos = SCREEN_CENTER - vec(50., 50.);
  vec ball_vel(10., -5.);
  Ball ball(ball_pos, ball_vel, 1.0, 15.0, sf::Color::Red);
  double distance_to_wall;

  // Create walls
  Wall wall_h1(vec(diff, diff), Y_, sf::Color::Red, width);
  Wall wall_v1(vec(diff, diff), X_, sf::Color::Green, height);
  Wall wall_h2(vec(width - diff, height - diff), Y_, sf::Color::Blue, width);
  Wall wall_v2(vec(width - diff, height - diff), X_, sf::Color::White, height);
  Wall wall_x(ZERO_VEC, vec(-1., .29), sf::Color::White, 2. * width);
  std::vector<Wall *> walls = {&wall_h1, &wall_v1, &wall_h2, &wall_v2, &wall_x};

  // Graphics setup
  sf::RenderWindow window(sf::VideoMode(width, height), "SFML graphics test");
  window.setMouseCursorVisible(false);

  // Main loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Physics
    ball.advance_by_dt(dt);
    for (auto wall:walls) {
      ball_pos = ball.get_pos();
      distance_to_wall = glm::length(wall->pt_projection(ball_pos)-ball_pos);
      if (distance_to_wall <= ball.get_radius())
        ball.collide_with_wall(*wall);
    }



    // Draw
    window.clear();
    for (auto wall : walls) {
      window.draw(wall->get_line_shape(), 2, sf::Lines);
    }
    window.draw(ball.get_shape());
    window.display();
  }
  return 0;
}
