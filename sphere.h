//
// Created by johnm on 2/20/2024.
//

#ifndef WEAKRAYTRACE_SPHERE_H
#define WEAKRAYTRACE_SPHERE_H


#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:

    // Creating a sphere by checking if our ray crosses the sphere.
// We translate the equation of a sphere: x^2+y^2+z^2 = r^2 to ray-sphere intersection values
// Values: a = b*b ; b = 2b * (A-C) ; c = (A-C) * (A-C) - r^2

/* First sphere equation
bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}
*/
// A vector dotted with itself is equal to the squared length.
// We can set b = 2h and simplify the expression.
    sphere(point3 _center, double _radius) : center(_center), radius(_radius) {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root) {
            root = (-half_b + sqrtd) / a;
            if (root <= ray_tmin || ray_tmax <= root)
                return false;
        }


        rec.t = root;
        rec.p = r.at(rec.t);

        // Determining the surface
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    }

private:
    point3 center;
    double radius;
};

#endif //WEAKRAYTRACE_SPHERE_H
