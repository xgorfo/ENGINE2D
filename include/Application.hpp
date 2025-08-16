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
    
    sf::RenderWindow window_;
    sf::View view_;
    Player player_;
    Game game_;
    
    sf::Font font_;
    
    enum class GameState {
        Menu,
        Playing,
        GameOver
    };
    
    GameState currentState_;
    
    void initializeFont();
    sf::Text createMenuText() const;
    sf::Text createGameOverText() const;
};
}