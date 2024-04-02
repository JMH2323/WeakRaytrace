//
// Created by johnm on 2/22/2024.
//

#ifndef WEAKRAYTRACE_INTERVAL_H
#define WEAKRAYTRACE_INTERVAL_H



class interval {
public:
    double min, max;

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double _min, double _max) : min(_min), max(_max) {}

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }

    static const interval empty, universe;
};

const static interval empty   (+infinity, -infinity);
const static interval universe(-infinity, +infinity);


#endif //WEAKRAYTRACE_INTERVAL_H