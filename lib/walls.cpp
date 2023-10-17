#include "walls.hpp"

Wall::Wall(const vec &p1, const vec &p2, const sf::Color &color) {
  // this->p1 = p1;
  // this->p2 = p2;
  // vec diff = p2-p1;
  // this->direction = glm::normalize(diff);
  // this->length = glm::length(diff);
  // this->normal = perp2d(this->direction);
  // this->color = color;
}

// Setters
void Wall::set_p1(const vec &pt) { this->p1 = pt; }
void Wall::set_p2(const vec &pt) { this->p2 = pt; }
void Wall::set_point(int index, const vec &pt) {
  switch (index) {
  deafult:
  case 1:
    this->p1 = pt;
  case 2:
    this->p2 = pt;
  }
}
void Wall::set_direction(const vec &direction) {
  this->direction = glm::normalize(this->p2 - this->p1);
}
void Wall::set_normal() { this->normal = perp2d(this->direction); }
void Wall::set_length() { this->length = glm::length(this->p2 - this->p1); }
void Wall::set_color(const sf::Color &color) {this->color = color;}
void Wall::set_color(int channel, int value) {
  switch (channel) {
  default:
  case RED:
    this->color.r = value;
  case GREEN:
    this->color.g = value;
  case BLUE:
    this->color.b = value;
  case ALPHA:
    this->color.a = value;
    break;
  }
}
