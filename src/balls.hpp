#ifndef BALLS
#define BALLS

#include "graphics.hpp"
#include "maths.hpp"
#include "walls.hpp"

class Ball {
  int id;
  vec pos, vel, display_diff;
  double mass, mass_inv, radius;
  sf::Color color;
  sf::CircleShape shape;

public:
  Ball();
  Ball(int id, const vec &pos, const vec &vel, double mass, double radius,
       const sf::Color &color);
  // ~Ball();

  // Getters
  int get_id() const;
  vec get_pos() const;
  double get_pos(int axis) const;
  vec get_vel() const;
  double get_vel(int axis) const;
  double get_mass() const;
  double get_mass_inv() const;
  double get_radius() const;
  sf::Color get_color() const;
  int get_color(int channel) const;
  sf::CircleShape get_shape() const;
  void get_data() const;

  // Setters
  void set_id(int id);
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

  // Dynamics
  void collide_with_wall(const Wall &wall);
  double time_to_wall_collision(const Wall &wall);
};

typedef std::vector<Ball> Balls_Vec;
typedef std::vector<Ball *> Balls_Ptr_Vec;

#endif // !BALLS
