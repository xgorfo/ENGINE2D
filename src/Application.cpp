#include "Application.hpp"
#include <iostream>

namespace Game {
Application::Application() : 
    game_(),
    player_(game_.groundLevel()),
    window_(videoModeFor(game_), "2D Engine"),
    view_(viewCenterFor(game_), viewSizeFor(game_)),
    font_(loadFont()) {
    
    window_.setView(view_);
    window_.setFramerateLimit(60);
}

sf::VideoMode Application::videoModeFor(const Game& game) {
    return sf::VideoMode(
        static_cast<unsigned int>(game.width()),
        static_cast<unsigned int>(game.height())
    );
}

sf::Vector2f Application::viewCenterFor(const Game& game) {
    return sf::Vector2f(game.width() / 2, game.height() / 2);
}

sf::Vector2f Application::viewSizeFor(const Game& game) {
    return sf::Vector2f(game.width(), game.height());
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
    
    if (game_.status() == Game::Status::Won) {
        currentState_ = ApplicationState::GameOver;
    }
}

void Application::render() {
    window_.clear(sf::Color::Black);
    
    switch (currentState_) {
        case ApplicationState::Menu: {
            auto text = createMenuText();
            centerText(text);
            window_.draw(text);
            break;
        }
            
        case ApplicationState::Playing:
            window_.draw(player_.getShape());
            for (const auto& obstacle : game_.obstacles()) {
                window_.draw(obstacle.getShape());
            }
            break;
            
        case ApplicationState::GameOver:
            window_.draw(player_.getShape());
            for (const auto& obstacle : game_.obstacles()) {
                window_.draw(obstacle.getShape());
            }
            auto text = createGameEndText();
            centerText(text);
            window_.draw(text);
            break;
    }
    
    window_.display();
}

void Application::centerText(sf::Text& text) const {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
    text.setPosition(game_.width() / 2, game_.height() / 2);
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
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);


    return text;
}

sf::Text Application::createGameEndText() const {
    sf::Text text;
    text.setFont(font_);
    
    if (game_.status() == Game::Status::Won) {
        text.setString("YOU WIN BRO");
        text.setFillColor(sf::Color::Green);
    } else {
        text.setString("GAME OVER");
        text.setFillColor(sf::Color::Red);
    }
    
    text.setCharacterSize(48);
    return text;
}
}

