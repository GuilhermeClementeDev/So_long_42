# So_long - 42 School

## Description

So_long is a project developed as part of the curriculum at 42 School. It is a 2D game where you navigate a character through a maze to collect items and reach the exit. The game is implemented in C, using the MinilibX graphics library.

## How to Clone

To clone the repository with its submodules, use the following command:

```bash
git clone --recurse-submodules git@github.com:GuilhermeClementeDev/So_long_42.git
```
## Requirements

Before running the project, make sure you have the following installed:

- MinilibX library (you can find instructions to install it on the MinilibX GitHub repository).
- A C compiler (like CC).

## Installation

1. Clone the repository:

    ```bash
    git clone --recurse-submodules git@github.com:GuilhermeClementeDev/So_long_42.git
    ```

2. Navigate to the project directory:

    ```bash
    cd So_long_42
    ```

3. Compile the project:

    ```bash
    make
    ```

4. Run the game:

    ```bash
    ./so_long [map_file.ber]
    ```

    Replace `[map_file.ber]` with the desired map file you want to play.

## Gameplay

- The player controls a character to move through a 2D map.
- The goal is to collect all the items (represented by collectibles) and find the exit.
- You will need to avoid obstacles like walls while navigating.

## Controls

- Arrow keys (Up, Down, Left, Right) or WASD to move the character.

## Project Requirements

The project must comply with the requirements set by 42 School:

- The player must be able to exit the game once all collectibles are collected.
- The game must have a valid map layout where each element (player, collectibles, walls, exit) is correctly placed.
