#include "Vector2D.h"

Vector2D::Vector2D(float x_, float y_) : x(x_), y(y_) {}
Vector2D Vector2D::operator+(const Vector2D& other) const { return Vector2D(x + other.x, y + other.y); }
Vector2D Vector2D::operator-(const Vector2D& other) const { return Vector2D(x - other.x, y - other.y); }
Vector2D Vector2D::operator*(float scalar) const { return Vector2D(x * scalar, y * scalar); }
