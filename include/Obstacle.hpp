#pragma once
#include <SFML/Graphics.hpp>

namespace Game {
class Obstacle {
public:
    Obstacle();
    
    void setPosition(float x, float y);
    const sf::RectangleShape& getShape() const;
    void move(float dx, float dy);

private:
    sf::RectangleShape shape_;
    
    static constexpr float width_ = 20.f;
    static constexpr float height_ = 20.f;
};
}