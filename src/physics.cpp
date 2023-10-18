#include "physics.hpp"

void ball_ball_interaction(Ball *b1, Ball *b2) {
  // The following values are calculated:
  // * du: difference in initial velocities between the balls (i.e. du = u_1 - u_2,
  // a vector).
  // * sum_inv_mass: 1/m_1 + 1/m_2.
  // * k: unit vector in the direction from x_2 to x_1 (x_i being the ith ball's
  // position, i.e. a vector).
  // * a: the change in momentum in the direction k, i.e. m_1(u_1-v_1) =
  // -m_2(u_2-v_2) = ak. This is derived using conservation of momentum.
  vec du = b1->get_vel() - b2->get_vel();
  double sum_inv_mass = b1->get_mass_inv() + b2->get_mass_inv();
  vec k = glm::normalize(b1->get_pos() - b2->get_pos());
  double a = glm::dot(k, du) / sum_inv_mass;

  // Using the above values the new velocities v1 and v2 are calculated.
  b1->set_vel(b1->get_vel() - (a / b1->get_mass()) * k);
  b2->set_vel(b2->get_vel() + (a / b2->get_mass()) * k);
}
