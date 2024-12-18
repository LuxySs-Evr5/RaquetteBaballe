# Arkanoid

## Description

This project is an implementation inspired by the classic Arkanoid game, developed in C++ using the Allegro graphics library. The game follows the Model-View-Controller (MVC) design pattern to separate responsibilities between game logic, rendering, and event control.

## Features

- Racket movement using the mouse
- Ball bouncing on various surfaces (bricks, walls, racket)
- Life management (3 lives at the start of each game)
- Score tracking with high score saving to a file
- Multiple levels encoded in `.txt` files
- Bricks of different colors awarding varying points
- Special bricks (silver and gold) with unique behaviors

## Prerequisites

- C++20
- Allegro 5
- g++
- make

## Installation

### On Debian-based systems:

1. Install the required dependencies (g++, make, and Allegro):
    ```sh
    sudo apt-get install g++ make liballegro5-dev
    ```

2. Compile the project:
    ```sh
    make
    ```

### On Arch Linux:

1. Install the required dependencies (g++, make, and Allegro):
    ```sh
    sudo pacman -S gcc make allegro
    ```

2. Compile the project:
    ```sh
    make
    ```

## Usage

To start the game, run the following command:
```sh
./arkanoid
```


## Game Controls

- `r` : Reset the high score to 0 (also saves to the file)
- `←` : Move to the previous level
- `→` : Move to the next level
- `espace` : Shoot a laser when available
- `q` : Quit the game

