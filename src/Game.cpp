#include "Game.hpp"
#include <cstdlib>
#include <algorithm>

namespace Game {
Game::Game() : 
    width_(800.f),
    height_(600.f),
    groundLevel_(500.f),
    playerStartPosition_{50.f, 500.f},
    obstacleSpawnChance_(1.f),
    platformSpeed_(90.f),
    obstacleSpacing_(240.f),
    duration_(30.f) {}

void Game::update(float deltaTime) {
    elapsedTime_ += deltaTime;

    if (elapsedTime_ >= duration_ && status_ == Status::Running) {
        status_ = Status::Won;
    }

    for (auto& obstacle : obstacles_) {
        obstacle.move(-platformSpeed_ * deltaTime, 0.f);
    }

    obstacles_.erase(std::remove_if(obstacles_.begin(), obstacles_.end(),
        [](const Obstacle& obstacle) {
            return obstacle.isLeftOf(0.f);
        }), obstacles_.end());

    if (rand() % 100 < obstacleSpawnChance_) {
        spawnObstacle();
    }
}

void Game::spawnObstacle() {
    float x;
    if (obstacles_.empty()) {
        x = width_;
    } else {
        x = obstacles_.back().getPosition().x + obstacleSpacing_;
    }

    Obstacle newObstacle;
    newObstacle.setPosition(x, groundLevel_);
    obstacles_.push_back(std::move(newObstacle));
}

void Game::reset() {
    obstacles_.clear();
    elapsedTime_ = 0.f;
    status_ = Status::Running;
}

bool Game::hasCollision(const Player& player) const {
    for (const auto& obstacle : obstacles_) {
        if (player.getShape().getGlobalBounds().intersects(obstacle.getShape().getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

Game::Status Game::status() const { 
    return status_; 
}

void Game::setStatus(Status status) { 
    status_ = status; 
}

const std::vector<Obstacle>& Game::obstacles() const { 
    return obstacles_; 
}

float Game::elapsedTime() const { 
    return elapsedTime_; 
}
}

