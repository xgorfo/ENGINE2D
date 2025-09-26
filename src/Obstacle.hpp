#pragma once
#include <SFML/Graphics.hpp>

namespace Game {
class Obstacle {
public:
    Obstacle();
    
    void setPosition(float x, float y);
    const sf::RectangleShape& getShape() const;
    void move(float dx, float dy);
    bool isLeftOf(float x) const;
    sf::Vector2f getPosition() const;

private:
    sf::RectangleShape shape_;
    
    static constexpr float width_ = 20.f;
    static constexpr float height_ = 20.f;
};
}

