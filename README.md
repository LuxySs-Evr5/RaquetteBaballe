# Arkanoid

## Description

This project is a game inspired by the classic Arkanoid game, developed in C++
using the Allegro graphics library. The game follows the Model-View-Controller
(MVC) design pattern to separate responsibilities between game logic,
rendering, and event control.

## Features

- Racket movement using the mouse
- Ball bouncing on various surfaces (bricks, walls, racket)
- Life management (3 lives at the start of each game)
- Score tracking with best score saving to a file
- Multiple levels encoded in `.txt` files
- Bricks of different colors awarding varying points
- Special bricks (silver and gold) with unique behaviors
- Game bonus in some bricks

## Prerequisites

- C++20
- Allegro 5
- g++
- make
- cmake

## Installation and Execution

### On Debian-based systems

1. Install the required dependencies (g++, make, cmake, and Allegro)

    ```sh
    sudo apt install g++ make cmake liballegro5-dev
    ```

2. Compile the project

    ```sh
    make
    ```

### On Arch Linux

1. Install the required dependencies (g++, make, cmake, and Allegro)

    ```sh
    sudo pacman -S gcc make cmake allegro
    ```

2. Compile the project

    ```sh
    make
    ```

### On Windows

1. **Install MinGW**:
   - Download MinGW from [MinGW-w64](https://www.mingw-w64.org/) or use a package manager like [MSYS2](https://www.msys2.org/).
   - Ensure that `g++`, `make`, and `cmake` are installed and added to your system `PATH`.

2. **Install Allegro**:
   - Using MSYS2, install Allegro with the following command:

    ```sh
     pacman -S mingw-w64-x86_64-allegro 
    ```

    - Verify that the necessary files are in the correct locations (`include` for headers, `lib` for libraries).

3. **Compile the Project**:
   - Open the MSYS2 MinGW terminal or CMD (if the `PATH` is set correctly), navigate to the project directory, and run:
    
    ```sh
     make
    ```

## Usage

After compilation, the executable will be available in the project root directory. For `Linux`, run the game with:

```sh
./arkanoid
```

For `Windows`, run the game with:

```cmd
arkanoid.exe
```

## Game Controls

- `r` : Reset the best score and current score to 0
- `←` : Move to the previous level
- `→` : Move to the next level
- `a` : Replay the current level
- `q` : Quit the game
- `spacebar` : Shoot a lazer when available
- `spacebar` : Release the ball when it is stuck to the racket

## Game Bonus

There are several bonuses available in the game. They will be displayed with
a letter inside the brick containing the bonus. You have to collect the
bonus with the racket. Here is a list of the different bonuses :

- Reduce the ball's speed
- Expand the racket's width
- Gain an extra life
- Shoot a lazer
- Make the ball stick to the racket and release it later
- Split the ball into three instances of itself. When this bonus is
active, no other bonuses will drop

## Create a Level

You can create as many levels as you want. Each level file must be placed in
the `ressources/levels` directory, saved in `.txt` format, and named with a
numeric filename (e.g., `1.txt`, `2.txt`). Each line in the file specifies a
brick to be placed on the map, using the following format:

- **Columns**:  
  1. **X-coordinate**: Position of the brick's center on the x-axis.  
  2. **Y-coordinate**: Position of the brick's center on the y-axis.  
  3. **Color**: Specify the color of the brick (see available options
      below).  
  4. *(Optional)* **Bonus**: Define a bonus that drops when the brick
      is destroyed (see available options below).

---

### Available Colors

- `defaultBrick`
- `white`
- `orange`
- `cyan`
- `green`
- `red`
- `blue`
- `magenta`
- `yellow`
- `silver`
- `gold`

---

### Available Bonuses

- `None`
- `SlowDown`
- `ExtraLife`
- `WideRacket`
- `StickyRacket`
- `SplitBall`
- `Lazer`

## Documentation

For detailed documentation, visit the [Arkanoid Wiki](https://github.com/Evr5/arkanoid/wiki).
