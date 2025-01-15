# Arkanoid

<div align="center">

<img src="other/arkanoid.webp" alt="Logo Arkanoid" width="400">

**A modern twist on the classic Arkanoid game, crafted with C++ and Allegro.**

[![Open Source](https://img.shields.io/badge/Open%20Source-%E2%9C%94-blue?style=for-the-badge)](https://github.com/Evr5/arkanoid)

</div>

---

## 📜 Description

**Arkanoid** is a game inspired by the classic brick-breaking arcade game. Developed in **C++** using the **Allegro graphics library**, it adheres to the **Model-View-Controller (MVC)** design pattern for clear separation of logic, rendering, and control. The project is fully **open-source**.

---

## 🌟 Supported Platforms

<div align="center">
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux" />
  <img src="https://img.shields.io/badge/macOS-000000?style=for-the-badge&logo=apple&logoColor=white" alt="macOS" />
  <img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows" />
</div>

---

## 🎮 Features

- **Dynamic Gameplay**: Racket movement using the mouse, with responsive ball physics.
- **Challenging Levels**: Multiple levels loaded from `.txt` files, featuring unique designs.
- **Score Tracking**: Tracks your score and saves the best score locally.
- **Diverse Bricks**: Various brick colors with different point values.
- **Special Bricks**: Silver and gold bricks with unique properties.
- **Game Bonuses**: Collect bonuses to gain extra lives, expand the racket, and more.

---

## 🔧 Prerequisites

- **C++20**
- **Allegro 5**
- **g++**
- **make**
- **cmake**

---

## 🚀 Installation

### 🐧 Linux (Debian-based)

1. Install dependencies:
    ```sh
    sudo apt install g++ make cmake liballegro5-dev
    ```
2. Compile the project:
    ```sh
    make
    ```

### 🐧 Linux (Arch Linux)

1. Install dependencies:
    ```sh
    sudo pacman -S gcc make cmake allegro
    ```
2. Compile the project:
    ```sh
    make
    ```

### 🍎 macOS

1. Install Allegro using Homebrew:
    ```sh
    brew install allegro
    ```
2. Compile the project:
    ```sh
    make
    ```

### 🪟 Windows

1. Install MinGW:
    - Download from [MinGW-w64](https://www.mingw-w64.org/) or use [MSYS2](https://www.msys2.org/).
    - Ensure `g++`, `make`, and `cmake` are installed and in your system PATH.
2. Install Allegro:
    - Using MSYS2:
      ```sh
      pacman -S mingw-w64-x86_64-allegro
      ```
3. Compile the project:
    ```sh
    make
    ```

---

## 🎲 Usage

After compiling, run the game:

- **Linux/macOS**:
  ```sh
  ./arkanoid
  ```
- **Windows**:
  ```cmd
  arkanoid.exe
  ```

---

## 🎮 Controls

- `r` : Reset the best score and current score.
- `←` : Move to the previous level.
- `→` : Move to the next level.
- `a` : Replay the current level.
- `q` : Quit the game.
- `Spacebar` : Shoot lasers or release the ball when stuck to the racket.

---

## 🎁 Bonuses

Collect bonuses by catching them with your racket. Each bonus is marked with a letter inside the corresponding brick:

- **S**: Slow down the ball.
- **E**: Gain an extra life.
- **W**: Expand the racket width.
- **L**: Shoot lasers.
- **T**: Make the ball stick to the racket.
- **B**: Split the ball into three.

---

## 🛠️ Create Your Levels

Design custom levels in the `ressources/levels` directory using `.txt` files. Name your files numerically (e.g., `1.txt`, `2.txt`). Format each line as follows:

- **X-coordinate**: Horizontal position of the brick.
- **Y-coordinate**: Vertical position of the brick.
- **Color**: Brick color (e.g., `red`, `blue`).
- **Bonus**: (Optional) Specify a bonus (`SlowDown`, `ExtraLife`, etc.).

---

## 📖 Documentation

For detailed guides and insights, visit the [Arkanoid Wiki](https://github.com/Evr5/arkanoid/wiki).

---

_Developed with ❤️ by [LuxySs](https://github.com/LuxySs) and [Evr5](https://github.com/Evr5)._  

</div>

