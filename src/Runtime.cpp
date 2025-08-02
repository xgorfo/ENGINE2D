#include "Runtime.h"

Runtime::Runtime() 
    : window(sf::VideoMode(800, 600), "2D Engine"), renderer(window) {
    entities.push_back(std::make_shared<Player>());
    auto triangle = std::make_shared<TriangleEntity>(Vector2D(400.f, 300.f));
    triangle->setVelocity(Vector2D(50.f, 0.f));
    entities.push_back(triangle);
}

void Runtime::run() {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();

        for (auto& entity : entities) {
            entity->update(dt);
        }

        renderer.clear();

        for (auto& entity : entities) {
            entity->render(renderer);
        }

        renderer.display();
    }
}
