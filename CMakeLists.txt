cmake_minimum_required(VERSION 3.27)
project(WeakRaytrace)

set(CMAKE_CXX_STANDARD 20)

add_executable(WeakRaytrace main.cpp
        vec3.h
        color.h
        hittable_list.h
        hittable.h
        ray.h
        sphere.h
        interval.h)

add_custom_command(
        TARGET WeakRaytrace POST_BUILD
        COMMAND WeakRaytrace > BigSphereSmallSphere.ppm
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generate BSSM.ppm"
)