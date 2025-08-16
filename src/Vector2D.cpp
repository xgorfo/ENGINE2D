#include "Vector2D.hpp"

namespace Game {
Vector2D operator+(const Vector2D& first, const Vector2D& second) {
    return Vector2D(first.x + second.x, first.y + second.y);
}

Vector2D& operator+=(Vector2D& first, const Vector2D& second) {
    first.x += second.x;
    first.y += second.y;
    return first;
}

Vector2D operator*(const Vector2D& vec, float scalar) {
    return Vector2D(vec.x * scalar, vec.y * scalar);
}

Vector2D operator*(float scalar, const Vector2D& vec) {
    return vec * scalar;
}
}