#include "Vector2D.hpp"

namespace Game {
Vector2D operator+(Vector2D first, Vector2D second) {
    first += second;
    return first;
}

Vector2D& operator+=(Vector2D& first, Vector2D second) {
    first.x += second.x;
    first.y += second.y;
    return first;
}

Vector2D operator*(Vector2D vec, float scalar) {
    vec *= scalar;
    return vec;
}

Vector2D operator*(float scalar, Vector2D vec) {
    return vec * scalar;
}

Vector2D& operator*=(Vector2D& vec, float scalar) {
    vec.x *= scalar;
    vec.y *= scalar;
    return vec;
}
}

