#include "maths.hpp"
#include <cmath>
#include <vector>

double distance1D(double a, double b) { return std::abs(a - b); }

vec perp2d(const vec &v) { return vec(-v.y, v.x); }
