#ifndef BALLS
#define BALLS

#include "graphics.hpp"
#include "maths.hpp"

class Ball {
  vec pos, vel;
  double mass, mass_inv, radius;
  sf::Color color;
  sf::CircleShape sphere_object;

public:
  Ball();
  Ball(const vec &pos, const vec &vel, double mass, double radius,
       const sf::Color &color);
  ~Ball();

  // Getters
  vec get_pos();
  double get_pos(int axis);
  vec get_vel();
  double get_vel(int axis);
  double get_mass();
  double get_mass_inv();
  double get_radius();
  sf::Color get_color();
  int get_color(int channel);

  // Setters
  void set_pos(const vec &p);
  void set_pos(int axis, double x);
  void set_vel(const vec &v);
  void set_vel(int axis, double v);
  void set_mass(double mass);
  void set_radius(double radius);
  void set_color(const sf::Color &color);
  void set_color(int channel, int value);

  // Graphics related
  void create_shape();

  // Movement
  void advance_by_dt(double dt);
  void advance_to_time(double time_next, double time_current);
};

#endif // !BALLS
