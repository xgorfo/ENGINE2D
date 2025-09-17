#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Player.hpp"

namespace Game {
class Application {
public:
    Application();
    void run();
 
private:
    void processEvents();
    void update(float deltaTime);
    void render();

    void processMenuEvents(const sf::Event& event);
    void processPlayingEvents(const sf::Event& event);
    void processGameOverEvents(const sf::Event& event);

    void centerText(sf::Text& text) const;

    static sf::VideoMode videoModeFor(const Game& game);
    static sf::Vector2f viewCenterFor(const Game& game);
    static sf::Vector2f viewSizeFor(const Game& game);

    Game game_;
    Player player_;
    sf::RenderWindow window_;
    sf::View view_;


    sf::Font font_;

    enum class ApplicationState {
        Menu,
        Playing,
        GameOver
    };

    ApplicationState currentState_ = ApplicationState::Menu;

    static sf::Font loadFont();
    sf::Text createMenuText() const;
    sf::Text createGameEndText() const;
};
}

