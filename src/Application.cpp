#include "Application.hpp"
#include <iostream>

namespace Game {
Application::Application() : 
    window_(sf::VideoMode(800, 600), "2D Engine"),
    view_(sf::Vector2f(400.f, 300.f), sf::Vector2f(800.f, 600.f)),
    currentState_(GameState::Menu) {
    
    window_.setView(view_);
    window_.setFramerateLimit(60);
    
    initializeFont();
}

void Application::run() {
    sf::Clock clock;
    
    while (window_.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        
        if (currentState_ == GameState::Playing) {
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
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                if (currentState_ == GameState::Menu) {
                    currentState_ = GameState::Playing;
                } else if (currentState_ == GameState::Playing) {
                    player_.jump();
                }
            }
            
            if (event.key.code == sf::Keyboard::R && currentState_ == GameState::GameOver) {
                player_.reset();
                game_.reset();
                currentState_ = GameState::Playing;
            }
        }
    }
}

void Application::update(float deltaTime) {
    player_.update(deltaTime);
    game_.update(deltaTime);
    
    if (game_.checkCollisions(player_)) {
        game_.setGameOver(true);
        currentState_ = GameState::GameOver;
    }
    
    if (game_.playerWon()) {
        currentState_ = GameState::GameOver;
    }
}

void Application::render() {
    window_.clear(sf::Color::Black);
    
    switch (currentState_) {
        case GameState::Menu:
            window_.draw(createMenuText());
            break;
            
        case GameState::Playing:
            window_.draw(player_.getShape());
            for (const auto& obstacle : game_.getObstacles()) {
                window_.draw(obstacle.getShape());
            }
            break;
            
        case GameState::GameOver:
            window_.draw(player_.getShape());
            for (const auto& obstacle : game_.getObstacles()) {
                window_.draw(obstacle.getShape());
            }
            window_.draw(createGameOverText());
            break;
    }
    
    window_.display();
}

void Application::initializeFont() {
    if (!font_.loadFromFile("assets/fonts/Lumos.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
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

sf::Text Application::createGameOverText() const {
    sf::Text text;
    text.setFont(font_);
    text.setString(game_.playerWon() ? "YOU WIN BRO" : "GAME OVER");
    text.setCharacterSize(static_cast<int>(window_.getSize().x * 0.1f));
    text.setFillColor(game_.playerWon() ? sf::Color::Green : sf::Color::Red);
    
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
    text.setPosition(window_.getSize().x / 2, window_.getSize().y / 2);
    
    return text;
}
}