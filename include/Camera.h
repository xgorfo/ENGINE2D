#pragma once
#include "Basis.h"
#include "Vector2D.h"

class Camera {
public:
    Camera();

    void move(const Vector2D& delta);
    Basis getBasis() const;

private:
    Vector2D position;
    float scale;
    float rotationDeg;
};
