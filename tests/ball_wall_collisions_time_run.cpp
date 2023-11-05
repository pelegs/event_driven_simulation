// ------------------------------------------ //
// THIS IS A VERY SILLY QUICK TEST            //
// (testing collision between ball and walls) //
// ------------------------------------------ //

#include "balls.hpp"
#include "events.hpp"
#include "graphics.hpp"
#include "json_read.hpp"
#include "maths.hpp"
#include "physics.hpp"
#include "walls.hpp"

#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <chrono>
#include <iostream>
#include <queue>
#include <thread>

void clear_queue(std::priority_queue<SimEvent> *pq) {
  while (!pq->empty())
    pq->pop();
}

SimEvent get_next_event_single_ball(std::priority_queue<SimEvent> *event_queue,
                                    std::vector<Wall *> walls, Ball *ball) {
  clear_queue(event_queue);
  for (auto wall : walls) {
    double time_to_collision = time_to_ball_wall_collision(ball, wall);
    SimEvent wall_collision(time_to_collision, ball, wall);
    if (time_to_collision > .01)
      event_queue->push(wall_collision);
  }
  return event_queue->top();
}

int main(int argc, char *argv[]) {
  // load json
  rapidjson::Document json_data = load_json("json/example2.json");
  System system = create_system(json_data);
  Ball *ball = system.get_ball(0);
  double next_event_time = -1., current_time = 0.;

  // Events management
  std::priority_queue<SimEvent> event_queue;
  SimEvent next_event =
      get_next_event_single_ball(&event_queue, system.get_walls(), ball);
  std::cout << next_event.event_time << std::endl;

  // Graphics setup
  sf::RenderWindow window(
      sf::VideoMode(system.get_width(), system.get_height()),
      "SFML graphics test");
  window.setMouseCursorVisible(false);

  // test
  sf::Font font;
  if (!font.loadFromFile(
          "/usr/share/fonts/truetype/HackNerdFont-Regular.ttf")) {
    std::cout << "Font error" << std::endl;
  }
  sf::Text text;
  int num_chars = 20;
  char buffer[num_chars];
  int num_events = 0;
  std::snprintf(buffer, num_chars, "%04d", num_events);
  std::string text_str(buffer);
  text.setFont(font); // font is a sf::Font
  text.setString(text_str);
  text.setCharacterSize(100); // in pixels, not points!
  text.setFillColor(sf::Color::Red);
  text.setStyle(sf::Text::Bold);

  // Main loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // Physics
    if (current_time + system.get_dt() > next_event_time) {
      // Move ball to collision time
      ball->advance_by_dt(next_event_time - current_time);
      ball_wall_interaction(ball, next_event.wall);

      // Calculate next event
      next_event =
          get_next_event_single_ball(&event_queue, system.get_walls(), ball);
      next_event_time = current_time + next_event.event_time;
    } else {
      current_time += system.get_dt();
      ball->advance_by_dt(system.get_dt());
    }
    num_events = event_queue.size();

    // Draw
    window.clear();

    system.draw(&window);
    std::snprintf(buffer, num_chars, "%04d", num_events);
    text_str = std::string(buffer);
    text.setString(text_str);
    window.draw(text);

    window.display();

    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  return 0;
}
