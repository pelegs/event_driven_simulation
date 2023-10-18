#include "lib/balls.hpp"
#include "lib/walls.hpp"
#include "lib/graphics.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    Ball ball_1(ZERO_VEC, ZERO_VEC, 2.0, 5.0, sf::Color::White);
    Ball ball_2(ZERO_VEC, ZERO_VEC, 1.0, 1.0, sf::Color::Red);

    std::cout << ball_1.get_mass_inv() << " " << ball_2.get_mass_inv() << std::endl;
    return 0;
}
