#pragma once
#include <cmath>

struct VectorCoordinate {
    float x;
    float y;

    // Default constructor
    VectorCoordinate() : x(0), y(0) {}

    // Constructor that sets x and y values
    VectorCoordinate(float x_, float y_) : x(x_), y(y_) {}

    // Addition operator overload
    VectorCoordinate operator+(const VectorCoordinate& v) const {
        return VectorCoordinate(x + v.x, y + v.y);
    }

    // Subtraction operator overload
    VectorCoordinate operator-(const VectorCoordinate& v) const {
        return VectorCoordinate(x - v.x, y - v.y);
    }

    // Scalar multiplication operator overload
    VectorCoordinate operator*(float scalar) const {
        return VectorCoordinate(x * scalar, y * scalar);
    }

    // Scalar division operator overload
    VectorCoordinate operator/(float scalar) const {
        return VectorCoordinate(x / scalar, y / scalar);
    }

    // Dot product of two vectors
    float dot(const VectorCoordinate& v) const {
        return x * v.x + y * v.y;
    }

    // Magnitude of vector
    float magnitude() const {
        return sqrt(x * x + y * y);
    }

    // Normalization of vector (i.e. making it a unit vector)
    VectorCoordinate normalize() const {
        float mag = magnitude();
        if (mag != 0) {
            return VectorCoordinate(x / mag, y / mag);
        }
        else {
            return VectorCoordinate();
        }
    }
};


/*
VectorCoordinate v1(1.0f, 2.0f);
VectorCoordinate v2(3.0f, 4.0f);

VectorCoordinate v3 = v1 + v2;
VectorCoordinate v4 = v2 * 2.0f;

float dotProduct = v1.dot(v2);
float magnitude = v3.magnitude();
VectorCoordinate normalized = v4.normalize();
*/