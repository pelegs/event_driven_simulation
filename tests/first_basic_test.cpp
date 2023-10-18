#include "../include/balls.hpp"
#include "../include/walls.hpp"
#include "../include/graphics.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    sf::Color test_color = sf::Color::Red;
    Ball ball_1(ZERO_VEC, ZERO_VEC, 2.0, 1.0, test_color);
    std::cout << ball_1.get_mass_inv() << std::endl;
    return 0;
}
