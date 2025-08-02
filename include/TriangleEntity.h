#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class TriangleEntity : public Entity {
public:
    TriangleEntity(float size, sf::Color color);
    void update(float dt) override;
    void render(Renderer& renderer) override;
    void setVelocity(const Vector2D& vel);
private:
    float size;
    sf::Color color;
    Vector2D velocity;
};