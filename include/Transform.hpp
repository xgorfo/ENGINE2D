
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "Vector2D.hpp"

class Transform {
public:
    Transform();
    Vector2D applyTransformation(const Vector2D& point) const;
    void setScale(float scaleX, float scaleY);
    void setRotation(float angle);

private:
    float scaleX, scaleY, rotation;
};

#endif
