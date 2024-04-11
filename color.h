//
// Created by johnm on 2/15/2024.
//

#ifndef WEAKRAYTRACE_COLOR_H
#define WEAKRAYTRACE_COLOR_H

#include "vec3.h"

#include <iostream>

using color = vec3;


inline double linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
        return sqrt(linear_component);

    return 0;
}


void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {

    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Use multisamples to update color on sum total of light
    //auto scale = 1.0 / samples_per_pixel;
    //r *= scale;
    //g *= scale;
    //b *= scale;

    // Apply a linear to gamma transform for gamma, adding gamma correction
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);


    // Write the translated value
    static const interval intensity(0.000, 0.999);
    out << static_cast<int>(256 * intensity.clamp(r)) << ' '
        << static_cast<int>(256 * intensity.clamp(g)) << ' '
        << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}

#endif //WEAKRAYTRACE_COLOR_H
