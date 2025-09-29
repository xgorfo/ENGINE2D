#include "Obstacle.hpp"

namespace Game {
Obstacle::Obstacle() {
    shape_.setSize(sf::Vector2f(width_, height_));
    shape_.setFillColor(sf::Color::Red);
}

void Obstacle::setPosition(float x, float y) {
    shape_.setPosition(x, y);
}

const sf::RectangleShape& Obstacle::getShape() const {
    return shape_;
}

void Obstacle::move(float dx, float dy) {
    shape_.move(dx, dy);
}

bool Obstacle::isLeftOf(float x) const {
    return shape_.getPosition().x + shape_.getSize().x < x;
}

sf::Vector2f Obstacle::getPosition() const {
    return shape_.getPosition();
}
}

