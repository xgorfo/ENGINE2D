#include "Game.hpp"
#include <cstdlib>
#include <algorithm>

namespace Game {
Game::Game() {}

void Game::update(float deltaTime) {
    elapsedTime_ += deltaTime;
    
    if (elapsedTime_ >= gameDuration_ && status_ == Status::Running) {
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
        x = 800.f;
    } else {
        x = obstacles_.back().getPosition().x + 240.f;
    }
    
    float y = 460.f;
    Obstacle newObstacle;
    newObstacle.setPosition(x, y);
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

Game::Status Game::getStatus() const { 
    return status_; 
}

void Game::setStatus(Status status) { 
    status_ = status; 
}

const std::vector<Obstacle>& Game::getObstacles() const { 
    return obstacles_; 
}

float Game::getElapsedTime() const { 
    return elapsedTime_; 
}
}

