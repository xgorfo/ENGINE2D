#include "TriangleEntity.h"

TriangleEntity::TriangleEntity(const Vector2D& pos)
    : position(pos), velocity(0.f, 0.f), color(sf::Color::Red) {}

void TriangleEntity::update(float dt) {
    position = position + velocity * dt;
}

void TriangleEntity::render(Renderer& renderer) {
    float size = 30.f;
    float h = size * 0.866f;

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

Vector2D TriangleEntity::getVelocity() const {
    return velocity;
}
