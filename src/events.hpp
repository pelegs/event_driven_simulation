#ifndef EVENTS
#define EVENTS

#include "balls.hpp"
#include "walls.hpp"
#include "physics.hpp"

#include <queue>

enum EventType {
  _EMPTY_EVENT = 0,
  _2_BALLS_COLLISION = 1,
  _BALL_WALL_COLLISION = 2
};

struct SimEvent {
  EventType type;
  bool active;
  double time_to_event;
  Wall *wall = NULL;
  Ball *ball_1 = NULL;
  Ball *ball_2 = NULL;

  SimEvent();
  SimEvent(double time_to_event, Ball *ball, Wall *wall);
  SimEvent(double time_to_event, Ball *ball_1, Ball *ball_2);
};

typedef std::priority_queue<SimEvent> EventQueue;

bool operator<(const SimEvent &lhs, const SimEvent &rhs);

void clear_event_queue(EventQueue *queue);

SimEvent get_next_event(std::priority_queue<SimEvent> *event_queue,
                        std::vector<Wall *> walls, std::vector<Ball *> balls);

#endif // !EVENTS
