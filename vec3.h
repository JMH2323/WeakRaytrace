//
// Created by johnm on 2/15/2024.
//

#ifndef WEAKRAYTRACE_VEC3_H
#define WEAKRAYTRACE_VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:
    // three element array to store vector components
    double e[3];

    ////// Constructors
    // Default
    vec3() : e{0,0,0} {}
    // Parameter Constructor
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    ////// Accesor methods
    double x() const { return e[0]; } // x component
    double y() const { return e[1]; } // y component
    double z() const { return e[2]; } // z component

    // Unary negation operator
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    // subscript for accessing elements
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    // Compound assignment operators
    vec3& operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(double t) {
        return *this *= 1/t;
    }


    // Calculation for  length
    double length() const {
        return sqrt(length_squared());
    }

    // Squared length calculation
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code.
using point3 = vec3;


// Vector Utility Functions

// Output operator overload
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Addition operator overload
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Subtraction operator overload
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Element-wise multipliction
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Scalar multiplication
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// Scalar multiplication (reverse)
inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

// Scalar division
inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

// Dot product
inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}

// Cross product calculation
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Normalization function
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}



#endif //WEAKRAYTRACE_VEC3_H
