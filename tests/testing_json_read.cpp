#include "json_read.hpp"
#include "system.hpp"
#include <rapidjson/document.h>

int main(int argc, char *argv[]) {
  rapidjson::Document json_data = load_json("json/example1.json");
  Balls_Vec balls = create_balls(json_data);
  Walls_Vec walls = create_walls(json_data);

  Balls_Ptr_Vec ball_ptrs;
  Walls_Ptr_Vec wall_ptrs;

  EventQueue events;
  Timer timer;

  double width = 700, height = 700;
  System system(width, height, 1., ball_ptrs, wall_ptrs, events, timer);

  // Graphics setup
  sf::RenderWindow window(sf::VideoMode(700, 700),
                          "Drawing from system - test");
  window.setMouseCursorVisible(false);

  // Main loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Draw
    window.clear();
    system.draw(&window);
    window.display();
  }

  return 0;
}
