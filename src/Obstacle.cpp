#include "Obstacle.hpp"

Obstacle::Obstacle() {
    shape.setSize(sf::Vector2f(20.f, 20.f));
    shape.setFillColor(sf::Color::Red);
}

void Obstacle::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

sf::RectangleShape Obstacle::getShape() const {
    return shape;
}

void Obstacle::move(float dx, float dy) {
    shape.move(dx, dy);
}
