#ifndef WALLS
#define WALLS

#include "graphics.hpp"
#include "maths.hpp"

class Wall {
  vec p1, p2, direction, normal;
  double length;
  sf::Color color;

public:
  Wall(const vec &p1, const vec &p2, const sf::Color &color);
  ~Wall();

  // Getters
  vec get_p1();
  vec get_p2();
  vec get_point(int index);
  vec get_direction();
  vec get_normal();
  double get_length();
  sf::Color get_color();
  int get_color(int channel);

  // Setters
  void set_p1(const vec &pt);
  void set_p2(const vec &pt);
  void set_point(int index, const vec &pt);
  void set_direction();
  void set_normal();
  void set_length();
  void set_color(const sf::Color &color);
  void set_color(int channel, int value);

  // Graphics related
};

#endif // !WALLS
