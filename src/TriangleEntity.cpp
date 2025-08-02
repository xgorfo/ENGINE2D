#include "TriangleEntity.h"
#include <cmath>

TriangleEntity::TriangleEntity(float size_, sf::Color color_)
    : size(size_), color(color_), velocity(0, 0) {}

void TriangleEntity::update(float dt) {
    position = position + velocity * dt;
}

void TriangleEntity::render(Renderer& renderer) {
    float h = size * std::sqrt(3.f) / 2.f;
    std::vector<Vector2D> points = {
        position + Vector2D(0.f, -h * 2.f / 3.f),
        position + Vector2D(-size / 2.f, h / 3.f),
        position + Vector2D(size / 2.f, h / 3.f)
    };
    renderer.drawPolygonWorld(points, color);
}

void TriangleEntity::setVelocity(const Vector2D& vel) {
    velocity = vel;
}