#include "balls.hpp"
#include "graphics.hpp"
#include "walls.hpp"
#include "physics.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  sf::Color test_color = sf::Color::Red;
  std::cout << "0x" << std::hex << test_color.toInteger() << std::endl;
  Ball ball_1(ZERO_VEC, vec(10.0, 0.), 1.337, 1.0, test_color);
  Ball ball_2(vec(5., 0.), vec(-16.6, 0.), 1.337, 1.0, test_color);
  std::cout << glm::to_string(ball_1.get_vel()) << " | "
            << glm::to_string(ball_2.get_vel()) << std::endl;
  ball_ball_interaction(&ball_1, &ball_2);
  std::cout << glm::to_string(ball_1.get_vel()) << " | "
            << glm::to_string(ball_2.get_vel()) << std::endl;
  return 0;
}
