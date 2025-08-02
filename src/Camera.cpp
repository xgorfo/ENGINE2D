#include "Camera.h"
#include <cmath>

Camera::Camera() : position(0, 0), scale(1.0f), rotationDeg(0.f) {}

void Camera::move(const Vector2D& delta) {
    position = position + delta;
}

Basis Camera::getBasis() const {
    float rad = rotationDeg * 3.14159265f / 180.f;
    float cosA = std::cos(rad) * scale;
    float sinA = std::sin(rad) * scale;
    return Basis(position, Vector2D(cosA, sinA), Vector2D(-sinA, cosA));
}
