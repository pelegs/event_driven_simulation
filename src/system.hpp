#ifndef SYSTEM
#define SYSTEM

#include "balls.hpp"
#include "events.hpp"
#include "graphics.hpp"
#include "physics.hpp"
#include "timer.hpp"
#include "walls.hpp"

class System {
  double width, height, dt;
  Balls_Ptr_Vec balls;
  Walls_Ptr_Vec walls;
  EventQueue event_queue;
  Timer timer;

public:
  System(double width, double height, double dt, const Balls_Ptr_Vec &balls,
         const Walls_Ptr_Vec &walls, const EventQueue &event_queue,
         const Timer &timer, double visible_wall_size);

  // Getters
  double get_width() const;
  double get_height() const;
  double get_dt() const;
  Ball *get_ball(int i) const;
  Wall *get_wall(int i) const;
  double get_current_time() const;

  // Add objects
  void add_ball(Ball *ball);
  void add_wall(Wall *wall);

  // Dynamics
  void calculate_interactions_for_ball(Ball *subject_ball, Ball *exclude_ball);
  void calculate_next_step();

  // Graphics
  void draw(sf::RenderWindow *window);
};

#endif // !SYSTEM
