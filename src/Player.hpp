#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.hpp"
#include "Obstacle.hpp"

namespace Game {
class Player {
public:
    enum class State {
        Grounded,
        Jumping,
        Falling
    };
    
    Player();
    
    void update(float deltaTime);
    void jump();
    void reset();
    
    const Vector2D& getPosition() const;
    const Vector2D& getSize() const;
    State getState() const;
    
    void setPosition(float x, float y);
    sf::RectangleShape getShape() const;

private:
    Vector2D position_;
    Vector2D size_;
    Vector2D velocity_;
    State state_ = State::Grounded;
    
    static constexpr float defaultSpeed_ = 60.f;
    static constexpr float jumpVelocity_ = -12.f;
    static constexpr float gravity_ = 0.3f;
    static constexpr float groundLevel_ = 460.f;
};
}

