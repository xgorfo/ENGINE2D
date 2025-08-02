#pragma once
#include "Basis.h"

class Camera {
public:
    Camera();
    void move(const Vector2D& delta);
    void zoom(float factor);
    void rotate(float angleDegrees);
    Basis getBasis() const;
private:
    Vector2D position;
    float scale;
    float rotationDeg;
};
