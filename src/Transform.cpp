#include "Transform.hpp"
#include <cmath>

namespace Game {
Vector2D Transform::apply(const Vector2D& point) const {
    float rad = rotation_ * (M_PI / 180.0f);
    float cosAngle = cos(rad);
    float sinAngle = sin(rad);

    float xNew = point.x * scaleX_ * cosAngle - point.y * scaleY_ * sinAngle;
    float yNew = point.x * scaleX_ * sinAngle + point.y * scaleY_ * cosAngle;

    return Vector2D(xNew, yNew);
}

void Transform::setScale(float scaleX, float scaleY) {
    scaleX_ = scaleX;
    scaleY_ = scaleY;
}

void Transform::setRotation(float angle) {
    rotation_ = angle;
}
} 