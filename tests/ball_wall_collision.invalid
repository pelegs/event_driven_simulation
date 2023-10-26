// ------------------------------------------ //
// THIS IS A VERY SILLY QUICK TEST            //
// (testing collision between ball and walls) //
// ------------------------------------------ //

#include "balls.hpp"
#include "events.hpp"
#include "graphics.hpp"
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

int main(int argc, char *argv[]) {
  // Parameters
  double width = 1500., height = 1500., diff = 100.;
  vec SCREEN_CENTER(width / 2., height / 2.);

  // Events management
  std::priority_queue<SimEvent> event_queue;
  bool create_first_event = true;

  // Create ball
  vec ball_pos = SCREEN_CENTER - vec(50., 50.);
  vec ball_vel = X_ - 0.25 * Y_;
  Ball ball(ball_pos, ball_vel, 1.0, 50.0, sf::Color::Red);
  double next_event_time = INFINITY, current_time = 0., dt = 5;

  // Create walls
  Wall wall_h1(0, vec(diff, diff), -Y_, sf::Color::Red, width);
  Wall wall_v1(1, vec(diff, diff), -X_, sf::Color::Green, height);
  Wall wall_h2(2, vec(width - diff, height - diff), Y_, sf::Color::Blue, width);
  Wall wall_v2(3, vec(width - diff, height - diff), X_, sf::Color::White,
               height);
  Wall wall_x(4, ZERO_VEC, vec(-1., .29), sf::Color::White, 2. * width);
  std::vector<Wall *> walls = {&wall_h1, &wall_v1, &wall_h2, &wall_v2, &wall_x};

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

    // Physics
    clear_queue(&event_queue);
    for (auto wall : walls) {
      double time_to_collision = ball.time_to_wall_collision(*wall);
      SimEvent wall_collision(time_to_collision, &ball, wall);
      if (time_to_collision > .01)
        event_queue.push(wall_collision);
    }
    SimEvent next_event = event_queue.top();
    next_event_time = current_time + next_event.time_to_event;
    ball.advance_by_dt(next_event.time_to_event);
    vec incident = ball.get_pos() - 100. * ball.get_vel();
    ball.collide_with_wall(*next_event.wall);

    // Draw
    window.clear();
    for (auto wall : walls) {
      window.draw(wall->get_line_shape(), 2, sf::Lines);
    }
    window.draw(ball.get_shape());

    // Draw vectors:
    // normal
    vec ball_center = ball.get_pos();
    vec wall_normal = ball_center - 100. * next_event.wall->get_normal();
    sf::Vertex ball_center_vertex = sf::Vertex(glm_to_sfml_vec2(ball_center));
    sf::Vertex wall_normal_vertex = sf::Vertex(glm_to_sfml_vec2(wall_normal));
    sf::Vertex normal_vector[2] = {ball_center_vertex, wall_normal_vertex};
    window.draw(normal_vector, 2, sf::Lines);
    // incident
    vec reflected = ball.get_pos() + 100. * ball.get_vel();
    sf::Vertex incident_vertex =
        sf::Vertex(glm_to_sfml_vec2(incident), sf::Color::Red);
    sf::Vertex reflected_vertex =
        sf::Vertex(glm_to_sfml_vec2(reflected), sf::Color::Green);
    sf::Vertex incident_vector[2] = {ball_center_vertex, incident_vertex};
    sf::Vertex reflected_vector[2] = {ball_center_vertex, reflected_vertex};
    window.draw(incident_vector, 2, sf::Lines);
    window.draw(reflected_vector, 2, sf::Lines);

    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  return 0;
}
