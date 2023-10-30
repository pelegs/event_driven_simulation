#include "timer.hpp"

Timer::Timer() {
  this->time = 0.;
  this->dt = 0.;
}

Timer::Timer(double t0, double dt) {
  this->time = t0;
  this->dt = dt;
}

void Timer::set_next_event(SimEvent *event) { this->next_event = event; }

SimEvent *Timer::get_next_event() { return this->next_event; }

void Timer::tick() {
  if (this->time + dt >= this->next_event->time_to_event)
    this->time = this->next_event->time_to_event;
  else
    this->time += this->dt;
  this->time_to_next_event = this->next_event->time_to_event - this->time;
}
