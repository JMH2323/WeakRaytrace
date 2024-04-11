

#include "WeakRaytrace.h"

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>

int main() {


    ////// World //////

    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    ////// Camera //////

    camera cam;

    ////// Image //////

    // Ratio of image width/height
    cam.aspect_ratio = 16.0 /9.0;
    // Rendered image width (pixels)
    cam.image_width = 400;
    // Count of random samples per pixel (antialiasing)
    cam.samples_per_pixel = 100;
    // Maximum number of a ray's bounces
    int max_depth = 50;


    ////// Render //////

   cam.render(world);

   }