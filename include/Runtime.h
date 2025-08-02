#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "TriangleEntity.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>

class Runtime {
public:
    Runtime();

    void run();

private:
    sf::RenderWindow window;
    Renderer renderer;
    std::vector<std::shared_ptr<Entity>> entities;
};
