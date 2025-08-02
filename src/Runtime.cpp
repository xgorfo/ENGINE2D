#include "Runtime.h"
#include "TriangleEntity.h"

Runtime::Runtime()
    : window(sf::VideoMode(800, 600), "2D Engine")
{
    Basis basis = camera.getBasis();
    renderer = new Renderer(window, basis);

    auto triangle = std::make_shared<TriangleEntity>(60.f, sf::Color::Red);
    triangle->setPosition(Vector2D(100.f, 100.f));
    triangle->setVelocity(Vector2D(30.f, 0.f));
    view.addEntity(triangle);
}

Runtime::~Runtime() {
    delete renderer;
}

void Runtime::run() {
    sf::Clock clock;
    while (running && window.isOpen()) {
        processEvents();
        float dt = clock.restart().asSeconds();
        update(dt);
        render();
    }
}

void Runtime::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            running = false;
            window.close();
        }
    }

    const float moveSpeed = 200.f;
    const float zoomFactor = 1.1f;
    const float rotateAngle = 5.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        camera.move(Vector2D(-moveSpeed * 0.016f, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        camera.move(Vector2D(moveSpeed * 0.016f, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        camera.move(Vector2D(0, -moveSpeed * 0.016f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        camera.move(Vector2D(0, moveSpeed * 0.016f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
        camera.zoom(zoomFactor);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
        camera.zoom(1.f / zoomFactor);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        camera.rotate(-rotateAngle);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        camera.rotate(rotateAngle);
    }
}

void Runtime::update(float dt) {
    view.update(dt);
    Basis basis = camera.getBasis();
    delete renderer;
    renderer = new Renderer(window, basis);
}

void Runtime::render() {
    renderer->clear();
    view.render(*renderer);
    renderer->display();
}