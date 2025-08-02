#pragma once
#include <SFML/Graphics.hpp>
#include "View.h"
#include "Renderer.h"
#include "Camera.h"

class Runtime {
public:
    Runtime();
    ~Runtime();
    void run();

private:
    sf::RenderWindow window;
    View view;
    Renderer* renderer;
    Camera camera;

    void processEvents();
    void update(float dt);
    void render();
    bool running = true;
};