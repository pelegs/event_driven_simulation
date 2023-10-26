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

SimEvent get_next_event(std::priority_queue<SimEvent> *event_queue,
                        std::vector<Wall *> walls, std::vector<Ball *> balls) {
  clear_queue(event_queue);
  for (auto ball_it_1 = balls.begin(); ball_it_1 != std::prev(balls.end());
       ++ball_it_1) {
    auto &ball_1 = *ball_it_1;
    for (auto ball_it_2 = (ball_it_1 + 1); ball_it_2 != balls.end();
         ++ball_it_2) {
      auto &ball_2 = *ball_it_2;
      double time_to_ball_ball_collision = time_to_collision(ball_1, ball_2);
      SimEvent ball_ball_collision(time_to_ball_ball_collision, ball_1, ball_2);
      if (time_to_ball_ball_collision > .01)
        event_queue->push(ball_ball_collision);
    }
    for (auto wall : walls) {
      double time_to_collision = ball_1->time_to_wall_collision(*wall);
      SimEvent wall_collision(time_to_collision, ball_1, wall);
      if (time_to_collision > .01)
        event_queue->push(wall_collision);
    }
  }

  return event_queue->top();
}

int main(int argc, char *argv[]) {
  // Parameters
  double width = 1500., height = 1500., diff = 50.;
  vec SCREEN_CENTER(width / 2., height / 2.);

  // Create balls
  Ball ball_1(SCREEN_CENTER, ZERO_VEC, 1.0, 20.,
              sf::Color::Red);
  Ball ball_2(vec(100., 100.), ZERO_VEC, 1.0, 20.,
              sf::Color::Green);
  std::vector<Ball *> balls = {&ball_1, &ball_2};

  // Create walls
  Wall wall_h1(0, vec(diff, diff), -Y_, sf::Color::Red, width);
  Wall wall_v1(1, vec(diff, diff), -X_, sf::Color::Green, height);
  Wall wall_h2(2, vec(width - diff, height - diff), Y_, sf::Color::Blue, width);
  Wall wall_v2(3, vec(width - diff, height - diff), X_, sf::Color::White,
               height);
  std::vector<Wall *> walls = {&wall_h1, &wall_v1, &wall_h2, &wall_v2};

  // Events management
  std::priority_queue<SimEvent> event_queue;
  SimEvent next_event = get_next_event(&event_queue, walls, balls);
  double next_event_time = next_event.time_to_event, current_time = 0., dt = atof(argv[1]);

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
     std::cout << glm::to_string(balls[0]->get_pos()) << std::endl;
     std::cout << glm::to_string(balls[1]->get_pos()) << std::endl;
     std::cout << "---------------------------------" << std::endl;

    // Physics
    if (current_time + dt > next_event_time) {
      // Move balls to collision time
      for (auto ball : balls)
        ball->advance_by_dt(next_event_time - current_time);
      if (next_event.type == _2_BALLS_COLLISION) {
        Ball *active_ball_1 = next_event.ball_1;
        Ball *active_ball_2 = next_event.ball_2;
        ball_ball_interaction(active_ball_1, active_ball_2);
      } else if (next_event.type == _BALL_WALL_COLLISION) {
        Ball *active_ball = next_event.ball_1;
        active_ball->collide_with_wall(*next_event.wall);
      }

      // Calculate next event
      next_event = get_next_event(&event_queue, walls, balls);
      next_event_time = current_time + next_event.time_to_event;
    } else {
      current_time += dt;
      for (auto ball : balls)
        ball->advance_by_dt(next_event_time - current_time);
      // std::cout << current_time << ", " << next_event.time_to_event << std::endl;
    }

    // Draw
    window.clear();
    for (auto wall : walls)
      window.draw(wall->get_line_shape(), 2, sf::Lines);
    for (auto ball : balls)
      window.draw(ball->get_shape());
    window.display();

    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  return 0;
}
