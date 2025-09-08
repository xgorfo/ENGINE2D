#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Obstacle.hpp"
#include "Player.hpp"

namespace Game {
class Game {
public:
    enum class Status {
        Running,
        Won,
        Lost
    };
    
    Game();
    
    void update(float deltaTime);
    void spawnObstacle();
    void reset();
    
    bool hasCollision(const Player& player) const;
    Status getStatus() const;
    
    void setStatus(Status status);
    
    const std::vector<Obstacle>& getObstacles() const;
    float getElapsedTime() const;

private:
    std::vector<Obstacle> obstacles_;
    float elapsedTime_ = 0.f;
    Status status_ = Status::Running;
    
    static constexpr float obstacleSpawnChance_ = 1.f;
    static constexpr float platformSpeed_ = 90.f;
    static constexpr float gameDuration_ = 30.f;
};
}

