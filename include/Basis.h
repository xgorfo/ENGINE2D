#pragma once
#include "Vector2D.h"

class Basis {
public:
    Basis(Vector2D origin = {}, Vector2D f1 = {1, 0}, Vector2D f2 = {0, 1});
    Vector2D toStandardCoords(const Vector2D& alphaBeta) const;
    Vector2D fromStandardCoords(const Vector2D& point) const;

private:
    Vector2D origin, f1, f2;
};
