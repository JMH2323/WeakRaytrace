//
// Created by johnm on 2/20/2024.
//

#ifndef WEAKRAYTRACE_WEAKRAYTRACE_H
#define WEAKRAYTRACE_WEAKRAYTRACE_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

// We need math constants and the space for future calculations.
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// returns a random real in 0 and 1
inline double random_double(){
    return rand() / (RAND_MAX + 1.0);
}

// Returns a random real in min and max
inline double random_double(double min, double max) {
    return min + (max-min)*random_double();
}

// Could use the <random> include as an alternative

// Common Inclusions

#include "ray.h"
#include "vec3.h"
#include "interval.h"


#endif //WEAKRAYTRACE_WEAKRAYTRACE_H
