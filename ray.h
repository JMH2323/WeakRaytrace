//
// Created by johnm on 2/15/2024.
//

#ifndef WEAKRAYTRACE_RAY_H
#define WEAKRAYTRACE_RAY_H

#include "vec3.h"

class ray {
public:
    ray() {}

    // Initializing Ray Constructor with necessary parameters
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    // returning our A and B values if needed.
    point3 origin() const  { return orig; }
    vec3 direction() const { return dir; }

    // Function P of t, where P(t) is equal to A + tB. where A is the origin and B is the ray direction
    point3 at(double t) const {
        return orig + t*dir;
    }

private:
    point3 orig;
    vec3 dir;
};


#endif //WEAKRAYTRACE_RAY_H
