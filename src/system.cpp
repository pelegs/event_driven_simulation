#include "system.hpp"
#include <iostream>

System::System() {
  this->width = 0.;
  this->height = 0.;
  this->dt = 0.;
}

System::System(double width, double height, double dt,
               const Balls_Ptr_Vec &balls, const Walls_Ptr_Vec &walls,
               const EventQueue &event_queue, const Timer &timer,
               double visible_wall_size = 1000.) {
  this->width = width;
  this->height = height;
  this->dt = dt;
  this->balls = balls;
  this->walls = walls;
  for (auto wall : this->walls)
    wall->set_line_shape(visible_wall_size);
  this->event_queue = event_queue;
  this->timer = timer;
}

// Getters
double System::get_width() const { return this->width; }
double System::get_height() const { return this->height; }
double System::get_dt() const { return this->dt; }
Ball *System::get_ball(int i) const { return this->balls[i]; }
Wall *System::get_wall(int i) const { return this->walls[i]; }
double System::get_current_time() const { return this->timer.time; }
Balls_Ptr_Vec System::get_balls() const { return this->balls; };
Walls_Ptr_Vec System::get_walls() const { return this->walls; };

// Add objects
void System::add_ball(Ball *ball) { this->balls.push_back(ball); }
void System::add_wall(Wall *wall) { this->walls.push_back(wall); }

// Dynamics
void System::calculate_interactions_for_ball(Ball *subject_ball,
                                             Ball *exclude_ball) {
  // Calculate all interactions with other balls, excluding exclude_ball
  for (auto iterated_ball : this->balls) {
    if (iterated_ball != subject_ball && iterated_ball != exclude_ball) {
      double event_time =
          time_to_ball_ball_collision(subject_ball, iterated_ball);
      SimEvent event(event_time, subject_ball, iterated_ball);
      this->event_queue.push(event);
    }
  }

  // Calculate all interactions with walls
  for (auto wall : this->walls) {
    double event_time = time_to_ball_wall_collision(subject_ball, wall);
    SimEvent event(event_time, subject_ball, wall);
    this->event_queue.push(event);
  }
}
void System::calculate_next_step() {}

// Graphics
void System::draw(sf::RenderWindow *window) {
  for (auto wall : walls)
    window->draw(wall->get_line_shape(), 2, sf::Lines);

  for (auto ball : balls)
    window->draw(ball->get_shape());
}
