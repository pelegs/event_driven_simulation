#include "json_read.hpp"
#include "system.hpp"
#include <iostream>
#include <rapidjson/document.h>

int main(int argc, char *argv[]) {
  rapidjson::Document json_data = load_json("json/example1.json");
  Balls_Ptr_Vec balls = create_balls(json_data);
  Walls_Ptr_Vec walls = create_walls(json_data);

  // for (auto ball : balls)
  //   std::cout << ball->get_id() << std::endl;
  // std::cout << "..." << std::endl;
  // for (auto wall : walls)
  //   std::cout << wall->get_id() << std::endl;
  // std::cout << "----------------" << std::endl;

  EventQueue events;
  Timer timer;

  double width = 700, height = 700;
  System system(width, height, 1., balls, walls, events, timer, width);

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
