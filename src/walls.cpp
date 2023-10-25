#include "walls.hpp"
#include <iostream>

Wall::Wall(int id, const vec &p0, const vec &normal, const sf::Color &color,
           double visible_length = 1000.0) {
  this->set_id(id);
  this->set_p0(p0);
  this->set_normal(glm::normalize(normal));
  this->set_color(color);
  this->set_line_shape(visible_length);
}

// Getters
int Wall::get_id() const { return this->id; }
vec Wall::get_p0() const { return this->p0; }
vec Wall::get_normal() const { return this->normal; }
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
sf::Vertex *Wall::get_line_shape() { return this->line_shape; }

// Setters
void Wall::set_id(int id) { this->id = id; }
void Wall::set_p0(const vec &pt) { this->p0 = pt; }
void Wall::set_normal(const vec &normal) { this->normal = normal; }
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
void Wall::set_line_shape(double visible_length) {
  vec d1 = visible_length * perp2d(this->normal);
  vec d2 = -d1;
  sf::Vertex p1 = sf::Vertex(glm_to_sfml_vec2(this->p0 + d1), this->color);
  sf::Vertex p2 = sf::Vertex(glm_to_sfml_vec2(this->p0 + d2), this->color);
  this->line_shape[0] = p1;
  this->line_shape[1] = p2;
}

// Graphics
// void Wall::draw(sf::RenderWindow &window) { window->draw(this->vertices, 2,
// sf::Lines); }

// Maths stuff
vec Wall::pt_projection(const vec &pt) {
  return project_pt_on_plane(pt, this->normal, this->p0);
}
