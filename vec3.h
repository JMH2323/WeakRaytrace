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

    // Checks if the vector is close to zero to prevent zero scatter direction and infinities
    bool near_zero() const {
        auto s = 1e-8;
        return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
    }

};

// Getting random vectors to be used in simple diffusion. returns xyz
static vec3 randomVec() {
    return vec3(random_double(), random_double(), random_double());
}

static vec3 randomVec(double min, double max) {
    return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
}



// point3 is just an alias for vec3, but useful for geometric clarity.
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

// Find a random point from within the sphere and check if its valid (inside and not outside the sphere)
inline vec3 random_in_unit_sphere() {
    while (true) {
        auto p = randomVec(-1, 1);
        if (p.length_squared() < 1)
            return p;
    }
}

inline vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}


// Take the dot product of the surface normal and r vector to check its in the correct hemisphere.
// dot positive = correct, negative = needs to be inverted
inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

// Reflection function. Takes a ray direction computation of v + 2b
inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n;
}


#endif //WEAKRAYTRACE_VEC3_H
