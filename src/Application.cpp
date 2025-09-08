#include "Application.hpp"
#include <iostream>

namespace Game {
Application::Application() : 
    window_(sf::VideoMode(800, 600), "2D Engine"),
    view_(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f)),
    font_(loadFont()) {
    
    window_.setView(view_);
    window_.setFramerateLimit(60);
}

void Application::run() {
    sf::Clock clock;
    
    while (window_.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        
        if (currentState_ == ApplicationState::Playing) {
            update(deltaTime);
        }
        
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_.close();
        }
        
        switch (currentState_) {
            case ApplicationState::Menu:
                processMenuEvents(event);
                break;
            case ApplicationState::Playing:
                processPlayingEvents(event);
                break;
            case ApplicationState::GameOver:
                processGameOverEvents(event);
                break;
        }
    }
}

void Application::processMenuEvents(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        currentState_ = ApplicationState::Playing;
    }
}

void Application::processPlayingEvents(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            player_.jump();
        }
    }
}

void Application::processGameOverEvents(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
        player_.reset();
        game_.reset();
        currentState_ = ApplicationState::Playing;
    }
}

void Application::update(float deltaTime) {
    player_.update(deltaTime);
    game_.update(deltaTime);
    
    if (game_.hasCollision(player_)) {
        game_.setStatus(Game::Status::Lost);
        currentState_ = ApplicationState::GameOver;
    }
    
    if (game_.getStatus() == Game::Status::Won) {
        currentState_ = ApplicationState::GameOver;
    }
}

void Application::render() {
    window_.clear(sf::Color::Black);
    
    switch (currentState_) {
        case ApplicationState::Menu:
            window_.draw(createMenuText());
            break;
            
        case ApplicationState::Playing:
            window_.draw(player_.getShape());
            for (const auto& obstacle : game_.getObstacles()) {
                window_.draw(obstacle.getShape());
            }
            break;
            
        case ApplicationState::GameOver:
            window_.draw(player_.getShape());
            for (const auto& obstacle : game_.getObstacles()) {
                window_.draw(obstacle.getShape());
            }
            window_.draw(createGameEndText());
            break;
    }
    
    window_.display();
}

sf::Font Application::loadFont() {
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/Lumos.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    return font;
}

sf::Text Application::createMenuText() const {
    sf::Text text;
    text.setFont(font_);
    text.setString("Press SPACE to start the game\n\nControls: SPACE - Jump\n\nRestart the game - R\n\nAvoid obstacles and reach the end!");
    text.setCharacterSize(static_cast<int>(window_.getSize().x * 0.05f));
    text.setFillColor(sf::Color::White);
    
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
    text.setPosition(window_.getSize().x / 2, window_.getSize().y / 2);
    
    return text;
}

sf::Text Application::createGameEndText() const {
    sf::Text text;
    text.setFont(font_);
    
    if (game_.getStatus() == Game::Status::Won) {
        text.setString("YOU WIN BRO");
        text.setFillColor(sf::Color::Green);
    } else {
        text.setString("GAME OVER");
        text.setFillColor(sf::Color::Red);
    }
    
    text.setCharacterSize(static_cast<int>(window_.getSize().x * 0.1f));
    
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
    text.setPosition(window_.getSize().x / 2, window_.getSize().y / 2);
    
    return text;
}
}

