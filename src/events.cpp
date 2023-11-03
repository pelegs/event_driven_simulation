#include "events.hpp"
#include "physics.hpp"
#include <cmath>

bool operator<(const SimEvent &lhs, const SimEvent &rhs) {
  return lhs.time_to_event > rhs.time_to_event;
}

SimEvent::SimEvent() {
  this->type = _EMPTY_EVENT;
  this->active = false;
  this->time_to_event = INFINITY;
}

SimEvent::SimEvent(double time_to_event, Ball *ball, Wall *wall) {
  this->type = _BALL_WALL_COLLISION;
  this->active = true;
  this->time_to_event = time_to_event;
  this->wall = wall;
  this->ball_1 = ball;
}

SimEvent::SimEvent(double time_to_event, Ball *ball_1, Ball *ball_2) {
  this->type = _2_BALLS_COLLISION;
  this->active = true;
  this->time_to_event = time_to_event;
  this->ball_1 = ball_1;
  this->ball_2 = ball_2;
}

void clear_event_queue(EventQueue *queue) {
  while (!queue->empty())
    queue->pop();
}

SimEvent get_next_event(std::priority_queue<SimEvent> *event_queue,
                        std::vector<Wall *> walls, std::vector<Ball *> balls) {
  clear_event_queue(event_queue);
  for (auto ball_it_1 = balls.begin(); ball_it_1 != std::prev(balls.end());
       ++ball_it_1) {
    auto &ball_1 = *ball_it_1;
    for (auto ball_it_2 = (ball_it_1 + 1); ball_it_2 != balls.end();
         ++ball_it_2) {
      auto &ball_2 = *ball_it_2;
      double event_time = time_to_ball_ball_collision(ball_1, ball_2);
      SimEvent ball_ball_collision(event_time, ball_1, ball_2);
      if (event_time > .01)
        event_queue->push(ball_ball_collision);
    }
    for (auto wall : walls) {
      double event_time = time_to_ball_wall_collision(ball_1, wall);
      SimEvent wall_collision(event_time, ball_1, wall);
      if (event_time > .01)
        event_queue->push(wall_collision);
    }
  }

  return event_queue->top();
}
