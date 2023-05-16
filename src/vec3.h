#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:

        // Constructors, null or set e values
        vec3() : e{0, 0, 0} {}

        vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

        // Get x, y, z
        float x() const { 
            return e[0]; 
        }

        float y() const { 
            return e[1]; 
        }

        float z() const { 
            return e[2]; 
        }

        // Negate vector
        vec3 operator-() const { 
            return vec3(-e[0], -e[1], -e[2]);
        }
        
        // Get vector coordinate at index
        float operator[](int i) const {
            return e[i];
        }
        
        // Get vector coordinate at index from pointer
        float& operator[](int i) {
            return e[i];
        }

        // add coordinates from v to vector
        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // multiply vector coordinates by constant t
        vec3& operator*=(const float t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // divide vector coordinates by constant t
        vec3& operator/=(const float t) {
            return *this *= 1/t;
        }

        // get length of vector
        float length() const {
            return sqrt(length_squared());
        }

        // Dot product of itself
        float length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    public:
        float e[3];

    
};

// Type alias
using point3 = vec3; //3D point
using color = vec3;  //RGB color

//-------------------------
// vec3 Utility Functions 
// (good for small function definitions to save performance and not add a bunch of space to
// the compiled software)
//-------------------------

// Print vector coordinates
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Add two vectors
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Subtract two vectors
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Multiply two vectors
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Multiply vector by constant
inline vec3 operator*(float t, const vec3 &v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}
inline vec3 operator*(const vec3 &v, float t) {
    return t * v;
}

// Divide vector by constant
inline vec3 operator/(vec3 v, float t) {
    return (1/t) * v;
}

// Dot product
inline float dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

// Cross product
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(
        u.e[1] * v.e[2] - u.e[2] * v.e[1],
        -(u.e[0] * v.e[2] - u.e[2] * v.e[0]),
        u.e[0] * v.e[1] - u.e[1] * v.e[0]
    );
}

// Unit vector
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif