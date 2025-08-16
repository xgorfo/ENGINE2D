#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Obstacle.hpp"
#include "Player.hpp"

namespace Game {
class Game {
public:
    Game();
    
    void update(float deltaTime);
    void spawnObstacle();
    void reset();
    
    bool checkCollisions(const Player& player) const;
    bool isGameOver() const;
    bool playerWon() const;
    
    void setGameOver(bool gameOver);
    void setPlayerWon(bool playerWon);
    
    const std::vector<Obstacle>& getObstacles() const;
    float getElapsedTime() const;

private:
    std::vector<Obstacle> obstacles_;
    float elapsedTime_;
    bool isGameOver_;
    bool playerWon_;
    
    static constexpr float obstacleSpawnChance_ = 1.f;
    static constexpr float platformSpeed_ = 90.f;
    static constexpr float gameDuration_ = 30.f;
};
}