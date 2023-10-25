#ifndef WALLS
#define WALLS

#include "graphics.hpp"
#include "maths.hpp"
#include <array>

class Wall {
  vec p0, normal;
  sf::Color color;
  sf::Vertex line_shape[2];

public:
  Wall(const vec &p0, const vec &normal, const sf::Color &color,
       double visible_length);

  // Getters
  vec get_p0() const;
  vec get_normal() const;
  sf::Color get_color() const;
  int get_color(int channel) const;
  sf::Vertex *get_line_shape();

  // Setters
  void set_p0(const vec &pt);
  void set_normal(const vec &normal);
  void set_color(const sf::Color &color);
  void set_color(int channel, int value);
  void set_line_shape(double visible_length);

  // Graphics related
  // void draw(sf::RenderWindow *window);
  
  // Maths stuff
  vec pt_projection(const vec &pt);
};

#endif // !WALLS
