//
// Created by johnm on 4/18/2024.
//

#ifndef WEAKRAYTRACE_MATERIAL_H
#define WEAKRAYTRACE_MATERIAL_H

#include "WeakRaytrace.h"
#include "hittable.h"


class hit_record;

class material {
public:
    virtual ~material() = default;

    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const {
        return false;
    }
};


class lambertian : public material {

public:
    lambertian(const color& albedo) : albedo(albedo) {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        auto scatter_direction = rec.normal + random_unit_vector();


        // Catch sum of zero scatter directions, preventing NaNs.
        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

private:
    color albedo;

};

class metal : public material {
public:
    metal(const color& albedo, double fuzz) : albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1) {}

    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        vec3 reflected = reflect(r_in.direction(), rec.normal);
        reflected = unit_vector(reflected) + (fuzz * random_unit_vector());
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

private:
    color albedo;
    // Fuzz: randomize the reflected using a small sphere and choosing a new endpoint within it.
    // bigger spheres result in more disarray or fuzz. Fuzz also consistently scales with the reflection vector.
    // This is done by normalizing the ray.
    double fuzz;
};

#endif //WEAKRAYTRACE_MATERIAL_H
