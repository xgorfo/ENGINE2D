# 2D Game Engine

A simple 2D game engine built with C++ and SFML, demonstrating core game development concepts including physics, collision detection, game state management, and rendering.

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![SFML](https://img.shields.io/badge/SFML-2.6.2-green.svg)
![CMake](https://img.shields.io/badge/CMake-3.10+-yellow.svg)
![Status](https://img.shields.io/badge/Status-In%20Development-orange.svg)
![License](https://img.shields.io/badge/License-MIT-brightgreen.svg)

## Features

- **Platformer Gameplay**: Control a character that must avoid obstacles for 30 seconds
- **Physics System**: Implemented gravity and jumping mechanics
- **Collision Detection**: Real-time collision detection between player and obstacles
- **Game State Management**: Menu, gameplay, and game over states
- **Obstacle Generation**: Random obstacle spawning system

## Technologies

- **C++17** - Core programming language
- **SFML 2.6** - Graphics and window management
- **CMake** - Build system

## Getting Started

### Prerequisites

- C++ compiler with C++17 support
- SFML 2.6+
- CMake 3.10+

### Installation & Build

```bash
# Clone the repository
git clone https://github.com/xgorfo/ENGINE2D.git
cd ENGINE2D

# Create build directory
mkdir build && cd build

# Build the project
cmake ..
make

# Run the application
.build/2d-engine
Controls

SPACE - Start game / Jump
R - Restart game after completion
🏗 Project Architecture

Modular structure with clear separation of concerns:

text
src/
├── Application.hpp/cpp    # Window management and main game loop
├── Game.hpp/cpp          # Game logic and state management
├── Player.hpp/cpp        # Character physics and movement
├── Obstacle.hpp/cpp      # Obstacle behavior and rendering
└── Vector2D.hpp/cpp      # 2D vector mathematics
Key Classes

Application: Manages the main game loop, event processing, and rendering
Game: Contains game logic, obstacle management, and collision detection
Player: Implements character physics, jumping, and gravity
Obstacle: Represents obstacles in the game world
Vector2D: Utility structure for 2D math operations

Contributing

Contributions are welcome! If you'd like to contribute:

Fork the repository
Create a feature branch (git checkout -b feature/amazing-feature)
Commit your changes (git commit -m 'Add some amazing feature')
Push to the branch (git push origin feature/amazing-feature)
Open a Pull Request
License

Project Team

xgorfo - Developer
