#ifndef MATHS
#define MATHS

#include <cmath>
#include <glm/ext/matrix_transform.hpp>
#include <vector>

// GLM-related
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <glm/glm.hpp>
#define assertm(exp, msg)                                                      \
  assert(((void)msg, exp)) // use (void) to silence unused warnings

// General constants
const double PERCISION = 1.0E-7;

// Physics vectors
const int num_dim = 2;
typedef glm::vec<num_dim, double> vec;
const vec ZERO_VEC = vec(0.0);

// 2D
const vec X_ = {1., .0};
const vec Y_ = {.0, 1.};
// 3D
// const vec X_ = {1., .0, .0};
// const vec Y_ = {.0, 1., .0};
// const vec Z_ = {.0, 1., .0};

// Row-columns related
const int ROW = 0;
const int COL = 1;
const int ALL_AXES = -1;
const int X_AX = 0;
const int Y_AX = 1;
const int FORWARD = 1;
const int BACKWARDS = -1;

// This is used for neighbor finding.
// 1D distance is defined so that there's no need to use expensive squares and
// square root in the case of distances in a single axis.
double distance1D(double, double);

// Given a 2D vector, return a perpendicular vector
// (note: there are two such vectors, this function returns the clock-wise 90
// rotated vector)
vec perp2d(const vec &v);

#endif // !MATHS