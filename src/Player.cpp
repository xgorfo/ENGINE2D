#include "Player.hpp"

namespace Game {
Player::Player(const Vector2D& startPosition, float groundLevel)
    : position_{startPosition},
      size_{40.f, 40.f},
      velocity_{0.f, 0.f},
      startPosition_{startPosition},
      groundLevel_(groundLevel) {}

void Player::update(float deltaTime) {
    if (state_ == State::Jumping || state_ == State::Falling) {
        position_.y += velocity_.y;
        velocity_.y += gravity_;

        if (velocity_.y > 0) {
            state_ = State::Falling;
        }

        if (position_.y >= groundLevel_) {
            position_.y = groundLevel_;
            velocity_.y = 0.f;
            state_ = State::Grounded;
        }
    }
}

void Player::jump() {
    if (state_ == State::Grounded) {
        velocity_.y = jumpVelocity_;
        state_ = State::Jumping;
    }
}

void Player::reset(const Vector2D& startPosition) {
    position_ = startPosition;
    velocity_ = {0.f, 0.f};
    state_ = State::Grounded;
    startPosition_ = startPosition;
}

const Vector2D& Player::getPosition() const { 
    return position_; 
}

const Vector2D& Player::getSize() const { 
    return size_; 
}

Player::State Player::getState() const { 
    return state_; 
}

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

