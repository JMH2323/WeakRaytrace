//
// Created by johnm on 4/2/2024.
//

#ifndef WEAKRAYTRACE_CAMERA_H
#define WEAKRAYTRACE_CAMERA_H

#include "WeakRaytrace.h"

#include "color.h"
#include "hittable.h"
#include <iostream>

class camera {

public:
    /* Public Camera Params */

    double aspect_ratio = 1.0;  // Ratio(width over height)
    int    image_width  = 100;  // Rendered pixel count
    int    samples_per_pixel = 10; // Number of random samples per pixel (blur)

    void render(const hittable& world) {

        initialize();

        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; ++j) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
                color pixel_color(0,0,0);
                for (int sample = 0; sample < samples_per_pixel; ++sample) {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, world);
                }

                write_color(std::cout, pixel_color, samples_per_pixel);
            }
        }

        std::clog << "\rDone.                 \n";
    }

  private:

    /* Private Camera Variables */

    int    image_height;   // Rendered image height
    point3 center;         // Camera center
    point3 pixel00_loc;    // Location of pixel 0, 0
    vec3   pixel_delta_u;  // Offset to pixel to the right
    vec3   pixel_delta_v;  // Offset to pixel below

    // We call initialize on camera instead of on owner to keep our main uncluttered
    // and avoid calling a number of setter methods.
    void initialize() {

        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        center = point3(0, 0, 0);

        // Determine viewport dimensions.
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);

        // Calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Calculate the location of the upper left pixel.
        auto viewport_upper_left =
                center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    }

    // Return a ray, used for random samples or future complexity
ray get_ray(int i, int j) const {

        // for the i,j location, get a random sampled ray
    auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
    auto pixel_sample = pixel_center + pixel_sample_square();

    auto ray_origin = center;
    auto ray_direction = pixel_sample - ray_origin;

    return ray(ray_origin, ray_direction);
}

// Returns a random point in the square surrounding a pixel
vec3 pixel_sample_square() const {
    auto px = -0.5 + random_double();
    auto py = -0.5 + random_double();
    return (px * pixel_delta_u) + (py * pixel_delta_v);
}

color ray_color(const ray& r, const hittable& world) const {

        // If ray hits an object, return its color
        hit_record rec;
        if (world.hit(r, interval(0,infinity), rec)) {
            return 0.5 * (rec.normal + color(1,1,1));
        }

        // Setting the back color which the ray will return using lerp (linear interpolation)
        // The lerp function: blendedValue = (1 - a) * startValue + a * endValue
        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5,0.7,1.0);

    }
};

#endif //WEAKRAYTRACE_CAMERA_H
