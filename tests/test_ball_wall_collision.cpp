// -------------------------------------------- //
// THIS IS A VERY SILLY QUICK TEST              //
// (testing drawing walls and their properties) //
// -------------------------------------------- //

#include "balls.hpp"
#include "graphics.hpp"
#include "maths.hpp"
#include "physics.hpp"
#include "walls.hpp"
#include <SFML/Graphics/Shape.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
  double width = 1500., height = 1500., diff = 5.;

  // Mouse related
  sf::Vector2f mouse_pos;
  double mouse_diameter = 10.0;
  sf::CircleShape mouse_cursor(mouse_diameter);
  sf::Vector2f mouse_circ_diff(mouse_diameter, mouse_diameter);
  mouse_cursor.setFillColor(sf::Color::Green);
  vec mouse_pos_vec = sfml_to_glm_vec2(mouse_pos);

  // Create walls
  Wall wall_h1(vec(diff, diff), Y_, sf::Color::Red, width);
  Wall wall_v1(vec(diff, diff), X_, sf::Color::Green, height);
  Wall wall_h2(vec(width - diff, height - diff), Y_, sf::Color::Blue, width);
  Wall wall_v2(vec(width - diff, height - diff), X_, sf::Color::White, height);
  Wall wall_x(ZERO_VEC, vec(-1., .29), sf::Color::White, 2.*width);
  std::vector<Wall *> walls = {&wall_h1, &wall_v1, &wall_h2, &wall_v2, &wall_x};

  // Lines to walls
  vec pt_on_wall;
  sf::Vertex line_to_wall[2] = {
      sf::Vertex(sf::Vector2f(0., 0.)),
      sf::Vertex(sf::Vector2f(1., 1.)),
  };

  // Graphics setup
  sf::RenderWindow window(sf::VideoMode(width, height), "SFML graphics test");
  window.setMouseCursorVisible(false);

  // Main loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    mouse_pos = sf::Vector2f(sf::Mouse::getPosition(window));
    mouse_cursor.setPosition(mouse_pos - mouse_circ_diff);
    mouse_pos_vec = sfml_to_glm_vec2(mouse_pos);

    window.clear();
    window.draw(mouse_cursor);
    for (long unsigned int i = 0; i < walls.size(); ++i) {
      window.draw(walls[i]->get_line_shape(), 2, sf::Lines);
      pt_on_wall = project_pt_on_plane(mouse_pos_vec, walls[i]->get_normal(),
                                       walls[i]->get_p0());
      line_to_wall[0] = mouse_pos;
      line_to_wall[1] = glm_to_sfml_vec2(pt_on_wall);
      window.draw(line_to_wall, 2, sf::Lines);
    }
    window.display();
  }
  return 0;
}
