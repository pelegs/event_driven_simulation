#ifndef TIMER
#define TIMER

#include "events.hpp"

struct Timer {
  double time, dt, time_to_next_event;
  SimEvent *next_event;

  Timer();
  Timer(double t0, double dt);
  void set_next_event(SimEvent *event);
  SimEvent *get_next_event();
  void tick();
};

#endif // !TIMER
