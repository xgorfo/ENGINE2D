
#include "Vector2D.hpp"

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

float Vector2D::getX() const { return x; }
float Vector2D::getY() const { return y; }

void Vector2D::set(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
}
