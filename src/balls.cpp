#include "balls.hpp"
#include "graphics.hpp"
#include <csignal>

Ball::Ball() {
  this->set_pos(ZERO_VEC);
  this->set_vel(ZERO_VEC);
  this->set_mass(1.0);
  this->set_radius(1.0);
  this->set_color(sf::Color::White);
  this->create_shape();
}

Ball::Ball(const vec &pos, const vec &vel, double mass, double radius,
           const sf::Color &color) {
  this->set_pos(pos);
  this->set_vel(vel);
  this->set_mass(mass);
  this->set_radius(radius);
  this->set_color(color);
  this->create_shape();
}

// Getters
vec Ball::get_pos()  const { return this->pos; }
double Ball::get_pos(int axis)  const { return this->pos[axis]; }
vec Ball::get_vel()  const { return this->vel; }
double Ball::get_vel(int axis)  const { return this->vel[axis]; }
double Ball::get_mass()  const { return this->mass; }
double Ball::get_mass_inv()  const { return this->mass_inv; }
double Ball::get_radius()  const { return this->radius; }
sf::Color Ball::get_color()  const { return this->color; }
int Ball::get_color(int channel)  const {
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

// Setters
void Ball::set_pos(const vec &p) { this->pos = p; }
void Ball::set_pos(int axis, double x) { this->pos[axis] = x; }
void Ball::set_vel(const vec &v) { this->vel = v; }
void Ball::set_vel(int axis, double v) { this->vel[axis] = v; }
void Ball::set_mass(double mass) {
  this->mass = mass;
  this->mass_inv = 1. / mass;
}
void Ball::set_radius(double radius) { this->radius = radius; }
void Ball::set_color(const sf::Color &color) {
  this->color = color;
  this->sphere_object.setFillColor(this->color);
}
void Ball::set_color(int channel, int value) {
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

// Graphics related
void Ball::create_shape() {
  this->sphere_object = sf::CircleShape(this->radius);
  this->sphere_object.setFillColor(this->color);
}

// Movement
void Ball::advance_by_dt(double dt) { this->pos += this->vel * dt; }
void Ball::advance_to_time(double time_next, double time_current) {
  this->advance_by_dt(time_next - time_current);
}
