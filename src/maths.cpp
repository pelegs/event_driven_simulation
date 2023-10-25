#include "maths.hpp"
#include <cmath>
#include <vector>

double distance1D(double a, double b) { return std::abs(a - b); }

vec perp2d(const vec &v) { return vec(-v.y, v.x); }

vec pt_to_plane(const vec &pt, const vec &normal, const vec &p0) {
  return glm::dot((pt - p0), normal) * normal * -1.;
  // -1. is for flipping the direction so that the returned vector points from
  // pt to the plane.
}

vec project_pt_on_plane(const vec &pt, const vec &normal, const vec &p0) {
  vec vec_from_pt_to_plane = pt_to_plane(pt, normal, p0);
  return pt + vec_from_pt_to_plane;
}

sf::Vector2f glm_to_sfml_vec2(const glm::vec<2, double> &vec) {
  return sf::Vector2f(vec.x, vec.y);
}

glm::vec<2, double> sfml_to_glm_vec2(const sf::Vector2f &vec) {
  return glm::vec<2, double>(vec.x, vec.y);
}

glm::vec<2, double> Vector2i_to_vec2(const sf::Vector2i &vec_i) {
  return vec((double)vec_i.x, (double)vec_i.y);
}
