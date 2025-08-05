#include "Application.hpp"
#include "Obstacle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Application::Application()
    : window(sf::VideoMode(800, 600), "2D Engine"),
      playerSpeed(100.f),
      playerVelocityY(0.f),
      isJumping(false),
      isGameOver(false),
      playerWon(false),
      elapsedTime(0.f),
      isGameStarted(false) {
    
    player.setSize(sf::Vector2f(40.f, 40.f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(50.f, 460.f);
    
    camera.setSize(sf::Vector2f(800.f, 600.f));
    camera.setCenter(player.getPosition());

    window.setFramerateLimit(60);
}

void Application::run() {
    sf::Clock clock;
    float deltaTime;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        processEvents();
        update();
        render();

        elapsedTime += deltaTime;
        if (elapsedTime >= 30.f && !isGameOver) {
            playerWon = true;
            isGameOver = true;
        }
    }
}

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space && !isGameStarted) {
                isGameStarted = true;
            }

            if (event.key.code == sf::Keyboard::R && isGameOver) {
                restartGame();
            }

            if (event.key.code == sf::Keyboard::Space && !isJumping && isGameStarted) {
                playerVelocityY = -16.f;
                isJumping = true;
            }
        }
    }
}

void Application::update() {
    if (!isGameStarted) return;

    if (isGameOver) return;

    float platformSpeed = 150.f;
    for (auto& obstacle : obstacles) {
        obstacle.move(-platformSpeed * 0.01f, 0.f);
    }

    if (isJumping) {
        playerVelocityY += 0.5f;
        player.move(0.f, playerVelocityY);

        for (auto& obstacle : obstacles) {
            if (player.getGlobalBounds().intersects(obstacle.getShape().getGlobalBounds())) {
                if (player.getPosition().y + player.getSize().y <= obstacle.getShape().getPosition().y) {
                    player.setPosition(player.getPosition().x, obstacle.getShape().getPosition().y - player.getSize().y);
                    playerVelocityY = 0.f;
                    isJumping = false;
                    break;
                }
            }
        }

        if (player.getPosition().y >= 460.f) {
            player.setPosition(player.getPosition().x, 460.f);
            playerVelocityY = 0.f;
            isJumping = false;
        }
    }

    camera.setCenter(400.f, 300.f);

    checkCollisions();

    if (rand() % 100 < 1) {
        spawnObstacle();
    }

    obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(),
        [](const Obstacle& obstacle) {
            return obstacle.getShape().getPosition().x + obstacle.getShape().getSize().x < 0;
        }), obstacles.end());
}

void Application::render() {
    window.clear(sf::Color::Black);

    if (!isGameOver && !isGameStarted) {
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/Lumos.ttf")) {
            std::cerr << "Error loading font!" << std::endl;
        }

        sf::Text text;
        text.setFont(font);
        text.setString("Press SPACE to start the game\n\nControls: SPACE - Jump\n\nRestart the game - R\n\nAvoid obstacles and reach the end!");

        int fontSize = static_cast<int>(window.getSize().x * 0.05f);
        text.setCharacterSize(fontSize);
        text.setFillColor(sf::Color::White);
        
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
        text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

        window.draw(text);
    }
    else {
        window.draw(player);

        for (const auto& obstacle : obstacles) {
            window.draw(obstacle.getShape());
        }

        if (isGameOver) {
            sf::Font font;
            if (!font.loadFromFile("assets/fonts/Lumos.ttf")) {
                std::cerr << "Error loading font!" << std::endl;
            }

            sf::Text text;
            text.setFont(font);
            text.setString(playerWon ? "YOU WIN BRO" : "GAME OVER");

            int fontSize = static_cast<int>(window.getSize().x * 0.1f);
            text.setCharacterSize(fontSize);
            text.setFillColor(playerWon ? sf::Color::Green : sf::Color::Red);

            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
            text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

            window.draw(text);
        }
    }

    window.display();
}

void Application::spawnObstacle() {
    float randomX;
    
    if (obstacles.empty()) {
        randomX = 800.f;
    } else {
        randomX = obstacles.back().getShape().getPosition().x + 40.f * 3;
    }

    float randomY = 490.f - 30.f;
    Obstacle newObstacle;
    newObstacle.setPosition(randomX, randomY);
    
    obstacles.push_back(newObstacle);
}

void Application::checkCollisions() {
    for (const auto& obstacle : obstacles) {
        if (player.getGlobalBounds().intersects(obstacle.getShape().getGlobalBounds())) {
            isGameOver = true;
        }
    }
}

void Application::restartGame() {
    player.setPosition(50.f, 460.f);
    playerVelocityY = 0.f;
    isJumping = false;
    isGameOver = false;
    playerWon = false;
    elapsedTime = 0.f;
    obstacles.clear();
    isGameStarted = false;
}
