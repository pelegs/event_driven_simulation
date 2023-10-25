#ifndef EVENTS
#define EVENTS

#include "balls.hpp"
#include "walls.hpp"

enum EventType { _EMPTY_EVENT = 0, _2_BALLS_COLLISION = 1, _BALL_WALL_COLLISION = 2 };

struct SimEvent {
  EventType type;
  bool active;
  double time_to_event;
  Wall* wall = NULL;
  Ball* ball_1 = NULL;
  Ball* ball_2 = NULL;

  SimEvent();
  SimEvent(double time_to_event, Ball *ball, Wall *wall);
  SimEvent(double time_to_event, Ball *ball_1, Ball *ball_2);
};

bool operator<(const SimEvent& lhs, const SimEvent& rhs);

#endif // !EVENTS
