
#include "Transform.hpp"
#include <cmath>

Transform::Transform() : scaleX(1.0f), scaleY(1.0f), rotation(0.0f) {}

Vector2D Transform::applyTransformation(const Vector2D& point) const {
    float rad = rotation * (M_PI / 180.0f);
    float cosAngle = cos(rad);
    float sinAngle = sin(rad);

    float xNew = point.getX() * scaleX * cosAngle - point.getY() * scaleY * sinAngle;
    float yNew = point.getX() * scaleX * sinAngle + point.getY() * scaleY * cosAngle;

    return Vector2D(xNew, yNew);
}

void Transform::setScale(float scaleX, float scaleY) {
    this->scaleX = scaleX;
    this->scaleY = scaleY;
}

void Transform::setRotation(float angle) {
    this->rotation = angle;
}
