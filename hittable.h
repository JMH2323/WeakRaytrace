//
// Created by johnm on 2/20/2024.
//

#ifndef WEAKRAYTRACE_HITTABLE_H
#define WEAKRAYTRACE_HITTABLE_H

#include "ray.h"

class hit_record {
public:
    point3 p;
    vec3 normal;
    double t;

    // Set up to determine if we are hitting the inside or outside based off -
    // the normal pointing "outward" or against the ray.
    bool front_face;
    void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }



};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};


#endif //WEAKRAYTRACE_HITTABLE_H
