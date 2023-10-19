#include "walls.hpp"

Wall::Wall(const vec &p1, const vec &p2, const sf::Color &color) {
  this->set_color(color); // We set this first since the color is needed
  this->set_p1(p1);
  this->set_p2(p2);
  this->set_direction();
  this->set_normal();
  this->set_length();
}

// Getters
vec Wall::get_p1() const { return this->p1; }
vec Wall::get_p2() const { return this->p2; }
vec Wall::get_point(int index) const {
  switch (index) {
  deafult:
    return this->p1;
  case 1:
    return this->p1;
  case 2:
    return this->p2;
  }
  return this->p1;
}
vec Wall::get_direction() const { return this->direction; }
vec Wall::get_normal() const { return this->normal; }
double Wall::get_length() const { return this->length; }
sf::Color Wall::get_color() const { return this->color; }
int Wall::get_color(int channel) const {
  switch (channel) {
  default:
    return COLOR_ERROR;
  case RED:
    return this->color.r;
  case GREEN:
    return this->color.g;
  case BLUE:
    return this->color.b;
  case ALPHA:
    return this->color.a;
    break;
  }
}
sf::Vertex* Wall::get_vertices() { return this->vertices; }

// Setters
void Wall::set_p1(const vec &pt) {
  this->p1 = pt;
  this->vertices[0] = sf::Vertex(glm_to_sfml_vec2(this->p1), this->color);
}
void Wall::set_p2(const vec &pt) {
  this->p2 = pt;
  this->vertices[1] = sf::Vertex(glm_to_sfml_vec2(this->p2), this->color);
}
void Wall::set_point(int index, const vec &pt) {
  switch (index) {
  case 1:
    this->p1 = pt;
  case 2:
    this->p2 = pt;
  }
}
void Wall::set_direction() {
  this->direction = glm::normalize(this->p2 - this->p1);
}
void Wall::set_normal() { this->normal = perp2d(this->direction); }
void Wall::set_length() { this->length = glm::length(this->p2 - this->p1); }
void Wall::set_color(const sf::Color &color) { this->color = color; }
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

// Graphics
// void Wall::draw(sf::RenderWindow &window) { window->draw(this->vertices, 2,
// sf::Lines); }
