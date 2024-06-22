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
        interval.h
        camera.h
        WeakRaytrace.h
        material.h)

add_custom_command(

        TARGET WeakRaytrace POST_BUILD
        COMMAND WeakRaytrace > FuzzyMetal.ppm
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generate test.ppm"


)