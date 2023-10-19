#ifndef WALLS
#define WALLS

#include "graphics.hpp"
#include "maths.hpp"
#include <array>

class Wall {
  vec p1, p2, direction, normal;
  sf::Vertex vertices[2];
  double length;
  sf::Color color;

public:
  Wall(const vec &p1, const vec &p2, const sf::Color &color);

  // Getters
  vec get_p1() const;
  vec get_p2() const;
  vec get_point(int index) const;
  vec get_direction() const;
  vec get_normal() const;
  double get_length() const;
  sf::Color get_color() const;
  int get_color(int channel) const;
  sf::Vertex *get_vertices();

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
  // void draw(sf::RenderWindow *window);
};

#endif // !WALLS
