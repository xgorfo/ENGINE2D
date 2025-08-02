#include "Player.h"

Player::Player() : position(100.f, 100.f), color(sf::Color::Green) {}

void Player::update(float dt) {
    // Простое движение вправо
    position = position + Vector2D(50.f * dt, 0.f);
}

void Player::render(Renderer& renderer) {
    std::vector<Vector2D> points = {
        position + Vector2D(-10.f, -10.f),
        position + Vector2D(10.f, -10.f),
        position + Vector2D(10.f, 10.f),
        position + Vector2D(-10.f, 10.f)
    };
    renderer.drawPolygonWorld(points, color);
}
