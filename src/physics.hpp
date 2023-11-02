#ifndef PHYSICS
#define PHYSICS

#include "balls.hpp"
#include "walls.hpp"

// Ball-Ball collisions
void ball_ball_interaction(Ball *b1, Ball *b2);
double time_to_ball_ball_collision(Ball *b1, Ball *b2);

// Ball-Wall collisions
void ball_wall_interaction(Ball *ball, Wall *wall);
double time_to_ball_wall_collision(Ball *ball, Wall *wall);

#endif // !PHYSICS
