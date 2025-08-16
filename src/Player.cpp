#include "Player.hpp"

namespace Game {
Player::Player() : 
    position_(50.f, 460.f), 
    size_(40.f, 40.f), 
    velocity_(0.f, 0.f), 
    isJumping_(false) {}

void Player::update(float deltaTime) {
    if (isJumping_) {
        position_.y += velocity_.y;
        velocity_.y += gravity_;
        
        if (position_.y >= 460.f) {
            position_.y = 460.f;
            velocity_.y = 0.f;
            isJumping_ = false;
        }
    }
}

void Player::jump() {
    if (!isJumping_) {
        velocity_.y = jumpVelocity_;
        isJumping_ = true;
    }
}

void Player::reset() {
    position_.x = 50.f;
    position_.y = 460.f;
    velocity_.x = 0.f;
    velocity_.y = 0.f;
    isJumping_ = false;
}

const Vector2D& Player::getPosition() const { return position_; }
const Vector2D& Player::getSize() const { return size_; }
bool Player::isJumping() const { return isJumping_; }

void Player::setPosition(float x, float y) {
    position_.x = x;
    position_.y = y;
}

sf::RectangleShape Player::getShape() const {
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(size_.x, size_.y));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position_.x, position_.y);
    return shape;
}
}