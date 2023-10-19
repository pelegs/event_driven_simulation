#include "maths.hpp"
#include <cmath>
#include <vector>

double distance1D(double a, double b) { return std::abs(a - b); }

vec perp2d(const vec &v) { return vec(-v.y, v.x); }

sf::Vector2f glm_to_sfml_vec2(const glm::vec<2, double> &vec) {
  return sf::Vector2f(vec.x, vec.y);
}

glm::vec<2, double> sfml_to_glm_vec2(const sf::Vector2f &vec){
  return glm::vec<2, double>(vec.x, vec.y);
}
