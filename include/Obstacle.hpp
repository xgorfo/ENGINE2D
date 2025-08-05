#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle();
    void setPosition(float x, float y);
    sf::RectangleShape getShape() const;
    void move(float dx, float dy);

private:
    sf::RectangleShape shape;
};

#endif
