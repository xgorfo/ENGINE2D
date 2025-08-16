#include "Game.hpp"
#include <cstdlib>

namespace Game {
Game::Game() : 
    elapsedTime_(0.f), 
    isGameOver_(false), 
    playerWon_(false) {}

void Game::update(float deltaTime) {
    elapsedTime_ += deltaTime;
    
    if (elapsedTime_ >= gameDuration_ && !isGameOver_) {
        playerWon_ = true;
        isGameOver_ = true;
    }
    
    for (auto& obstacle : obstacles_) {
        obstacle.move(-platformSpeed_ * deltaTime, 0.f);
    }
    
    obstacles_.erase(std::remove_if(obstacles_.begin(), obstacles_.end(),
        [](const Obstacle& obstacle) {
            return obstacle.getShape().getPosition().x + obstacle.getShape().getSize().x < 0;
        }), obstacles_.end());
    
    if (rand() % 100 < obstacleSpawnChance_) {
        spawnObstacle();
    }
}

void Game::spawnObstacle() {
    float randomX;
    if (obstacles_.empty()) {
        randomX = 800.f;
    } else {
        randomX = obstacles_.back().getShape().getPosition().x + 80.f * 3;
    }
    
    float randomY = 460.f;
    Obstacle newObstacle;
    newObstacle.setPosition(randomX, randomY);
    obstacles_.push_back(std::move(newObstacle));
}

void Game::reset() {
    obstacles_.clear();
    elapsedTime_ = 0.f;
    isGameOver_ = false;
    playerWon_ = false;
}

bool Game::checkCollisions(const Player& player) const {
    for (const auto& obstacle : obstacles_) {
        if (player.getShape().getGlobalBounds().intersects(obstacle.getShape().getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

bool Game::isGameOver() const { return isGameOver_; }
bool Game::playerWon() const { return playerWon_; }

void Game::setGameOver(bool gameOver) { isGameOver_ = gameOver; }
void Game::setPlayerWon(bool playerWon) { playerWon_ = playerWon; }

const std::vector<Obstacle>& Game::getObstacles() const { return obstacles_; }
float Game::getElapsedTime() const { return elapsedTime_; }
}