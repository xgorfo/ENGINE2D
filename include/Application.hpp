#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Obstacle.hpp"

class Application {
public:
    Application();
    void run();
    
private:
    void processEvents();
    void update();
    void render();
    void spawnObstacle();
    void checkCollisions();
    void restartGame();
    
    sf::RenderWindow window;
    sf::RectangleShape player;
    sf::View camera;
    
    std::vector<Obstacle> obstacles;
    float playerSpeed;
    float playerVelocityY;
    bool isJumping;
    bool isGameOver;
    bool playerWon;
    bool isGameStarted;
    
    float elapsedTime;
};

#endif
