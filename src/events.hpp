#ifndef EVENTS
#define EVENTS

enum EventType { _2_BALLS_COLLISION = 1, _BALL_WALL_COLLISION = 2 };

struct SimEvent {
  bool active;
  double time;
  EventType type;
  // Wall* wall;
  // Particle* p1, p2;
};

#endif // !EVENTS
