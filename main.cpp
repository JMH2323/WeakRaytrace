#include <iostream>
#include "color.h"
#include "ray.h"
#include "vec3.h"


////// Environment (colors, shapes) //////

// Creating a sphere by checking if our ray crosses the sphere.
// We translate the equation of a sphere: x^2+y^2+z^2 = r^2 to ray-sphere intersection values
// Values: a = b*b ; b = 2b * (A-C) ; c = (A-C) * (A-C) - r^2
bool hit_sphere(const point3& center, double radius, const ray& r) {

    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}


color ray_color(const ray& r){

    // Checking for sphere collision
    if (hit_sphere(point3(0,0,-1), 0.5, r))
        return color(1,1,0);

    // Setting the color which the reay will return using lerp (linear interpolation)
    // The lerp function: blendedValue = (1 - a) * startValue + a * endValue
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.7,0.5,1.0);

}

int main() {

    ////// Image //////

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;


    ////// Camera //////

    auto focal_length = 1.0;

    // Viewport widths less than one are ok since they are 'real' valued.
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

    auto camera_center = point3(0,0,0);

    // Calculate vectors across horizontal and down vertical viewpoint edges
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors (done on the pixel-level)
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel100_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);



    ////// Render //////

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel100_loc + (i * pixel_delta_u) + (j * pixel_delta_v);

            // Set ray direction and cast the ray
            // Ray direction is not a unit vector for simplicity and speed.
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\r Done                  \n";
}