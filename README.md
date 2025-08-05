 # 2D Platformer Game Engine

This is a simple 2D platformer game engine built using **SFML** (Simple and Fast Multimedia Library) in **C++**. The game features a player-controlled character that can jump, avoid obstacles, and reach the end of a level within 30 seconds.

## Features

- **Player Movement**: The player can jump over obstacles.
- **Obstacles**: Spawned obstacles that the player needs to avoid.
- **Jumping Mechanism**: The player can jump at a height twice their size.
- **Game Timer**: The game lasts for 30 seconds, after which the player either wins or loses.
- **Collision Detection**: The player loses if they collide with an obstacle.
- **Restart Mechanism**: After the game ends, the player can restart by pressing `R`.
- **Controls**:
    - `Space`: Start the game or jump.
    - `R`: Restart the game after it ends.
  
## Requirements

Before running the game, ensure that you have **SFML** installed on your machine.

### Install SFML (if not installed)

On macOS (using Homebrew):
brew install sfml

On Windows:
Follow the instructions on the official SFML website: SFML Installation Guide
Compilation Instructions
Clone the repository:
git clone https://github.com/yourusername/2d-engine.git
cd 2d-engine
Build using CMake:
mkdir build
cd build
cmake ..
make

Run the game:
./2d-engine

Game Controls
- Spacebar: Start the game, jump, or continue after winning/losing.
- R: Restart the game after it ends.
How the Game Works
The game consists of a simple platformer engine:
The player (a green square) moves to the right automatically.
The player can jump to avoid obstacles (red squares) that appear randomly on the screen.
The game lasts for 30 seconds, and the player must avoid the obstacles during that time.
- If the player collides with any obstacle, the game ends and shows a "Game Over" message.
- If the player survives for 30 seconds, a "You Win" message will be displayed.
## Screenshots
- Here are some screenshots of the game in action:


<img width="793" height="624" alt="Screenshot 2025-08-05 at 1 20 49 PM" src="https://github.com/user-attachments/assets/5ed47ece-ee1f-448c-9188-e90f019ab1dc" />

<img width="1562" height="1174" alt="image" src="https://github.com/user-attachments/assets/3d556037-fb46-4cf3-8020-5684eda20723" />

<img width="806" height="609" alt="Screenshot 2025-08-05 at 1 22 00 PM" src="https://github.com/user-attachments/assets/90f68af6-5ab9-4c37-8728-32e6393e67df" />

<img width="790" height="617" alt="Screenshot 2025-08-05 at 1 22 45 PM" src="https://github.com/user-attachments/assets/35ca5ba1-4817-4ba9-b2e2-64a605a1e829" />



Made with а чо мы тут на английском разговорились :) ❤️

