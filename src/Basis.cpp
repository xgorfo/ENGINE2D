#include "Basis.h"

Basis::Basis(Vector2D origin_, Vector2D f1_, Vector2D f2_) 
    : origin(origin_), f1(f1_), f2(f2_) {}

Vector2D Basis::toStandardCoords(const Vector2D& alphaBeta) const {
    return origin + f1 * alphaBeta.x + f2 * alphaBeta.y;
}

Vector2D Basis::fromStandardCoords(const Vector2D& point) const {
    Vector2D p = point - origin;
    float det = f1.x * f2.y - f2.x * f1.y;
    float a = (p.x * f2.y - p.y * f2.x) / det;
    float b = (p.y * f1.x - p.x * f1.y) / det;
    return {a, b};
}
