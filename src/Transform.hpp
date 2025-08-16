#pragma once
#include "Vector2D.hpp"

namespace Game {
class Transform {
public:
    Transform() = default;
    
    Vector2D apply(const Vector2D& point) const;
    void setScale(float scaleX, float scaleY);
    void setRotation(float angle);

private:
    float scaleX_ = 1.0f;
    float scaleY_ = 1.0f;
    float rotation_ = 0.0f;
};
}