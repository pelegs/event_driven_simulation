#ifndef WALLS
#define WALLS

#include "graphics.hpp"
#include "maths.hpp"
#include <array>

class Wall {
  int id;
  vec p0, normal;
  sf::Color color;
  sf::Vertex line_shape[2];

public:
  Wall(int id, const vec &p0, const vec &normal, const sf::Color &color);

  // Getters
  int get_id() const;
  vec get_p0() const;
  vec get_normal() const;
  sf::Color get_color() const;
  int get_color(int channel) const;
  sf::Vertex *get_line_shape();
  void get_data() const;

  // Setters
  void set_id(int id);
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

typedef std::vector<Wall *> Walls_Ptr_Vec;
typedef std::vector<Wall> Walls_Vec;

#endif // !WALLS
