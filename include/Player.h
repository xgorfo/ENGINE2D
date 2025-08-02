#pragma once

#include "Entity.h"
#include "Vector2D.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>

class Player : public Entity {
public:
    Player();
    void update(float dt) override;
    void render(Renderer& renderer) override;

private:
    Vector2D position;
    sf::Color color;
};
