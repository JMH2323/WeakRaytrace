//
// Created by johnm on 2/20/2024.
//

#ifndef WEAKRAYTRACE_HITTABLE_LIST_H
#define WEAKRAYTRACE_HITTABLE_LIST_H


#include "hittable.h"

#include <memory>
#include <vector>



// Using a shared pointer allows multiple shapes to share a common instance.
using std::shared_ptr;
using std::make_shared;


// hittable list class maintains all objects that can be hit by a ray.
class hittable_list : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;

    // Constructor
    hittable_list() {}

    // Constructor that adds an object
    hittable_list(shared_ptr<hittable> object) { add(object); }

    // Add ability to clear objects
    void clear() { objects.clear(); }

    // Adding new objects
    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    // Sort through all objects in the list and check ray intersections -
    // from the interval we describe.
    // If rays hit, it records the hit details into 'rec' and returns hit result.
    bool hit(const ray &r, interval ray_t, hit_record &rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;

        for (const auto &object: objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};
#endif //WEAKRAYTRACE_HITTABLE_LIST_H
