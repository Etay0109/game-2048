# Game 2048

A simple implementation of the classic 2048 puzzle game.
This version adds multiple stages and supports keyboard commands (R, L, D, U) for control.

## Game Overview

- 2048 is a single-player sliding tile puzzle game.
- 🎯 The goal is to combine tiles through the stages until you reach 2048.
- Stage 1: Reach the tile 16 ⭐
- Stage 2: Reach the tile 32 ⭐⭐ 
- Stage 3: Reach the tile 2048 ⭐⭐⭐
- 👉 Each time you win one board, you automatically advance to the next stage.

## 🎮 How to Play

- The game is played on a **grid board** where tiles slide in the chosen direction.  
- On every move, a new tile (2 or 4) appears on the board.  
- When two tiles with the same number collide, they **merge** into one tile with double the value.  

### 🕹️ Controls

You can use the following keys to move the tiles:
- `u` ⬆️ → Move tiles **up**
- `d` ⬇️ → Move tiles **down**
- `l` ⬅️ → Move tiles **left**
- `r` ➡️ → Move tiles **right**

## Features

- Classic 2048 gameplay
- Intuitive controls
- Responsive design

## 🖼️ Demo

<img src="screenshot.png" alt="Game Demo" width="400"/>


## Getting Started


### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/Etay0109/game-2048.git
    cd game-2048
    ```
2. Run the game:
    ```bash
    ./Game2048
    ```
