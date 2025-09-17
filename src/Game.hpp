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
    Status status() const;

    void setStatus(Status status);

    const std::vector<Obstacle>& obstacles() const;
    float elapsedTime() const;

    float width() const { return width_; }
    float height() const { return height_; }
    float groundLevel() const { return groundLevel_; }

private:
    std::vector<Obstacle> obstacles_;
    float elapsedTime_ = 0.f;
    Status status_ = Status::Running;

    float width_;
    float height_;
    float groundLevel_;
    float obstacleSpawnChance_;
    float platformSpeed_;
    float duration_;
};
}

