#include "events.hpp"

bool operator<(const SimEvent &lhs, const SimEvent &rhs) {
  return lhs.time_to_event > rhs.time_to_event;
}

SimEvent::SimEvent() {
  this->type = _EMPTY_EVENT;
  this->active = false;
  this->time_to_event = -1.0;
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
