#ifndef PHYSICS
#define PHYSICS

#include "balls.hpp"
#include "walls.hpp"

void ball_ball_interaction(Ball *b1, Ball *b2);

double time_to_collision(Ball *b1, Ball *b2);
// double time_to_collision(Ball *b, Wall *w);

vec vel_wall_intersection_pt(const Ball &ball, const Wall &wall);

#endif // !PHYSICS
