<div align="center">

<h1 style="font-size: 3em; margin-bottom: 10px;">Arkanoid</h1>

<img src="other/arkanoid.png" alt="Logo Arkanoid" width="200" style="margin: 20px 0;">

<p><strong>A modern twist on the classic Arkanoid game, crafted with C++ and Allegro.</strong></p>

<a href="https://github.com/Evr5/arkanoid">
  <img src="https://img.shields.io/badge/Open%20Source-%E2%9C%94-blue?style=for-the-badge" alt="Open Source">
</a>

</div>

---

<h2 align=center>📜 Description</h2>

<p style="max-width: 600px; text-align: justify;">
<strong>Arkanoid</strong> is a game inspired by the classic brick-breaking arcade game. Developed in <strong>C++</strong> using the <strong>Allegro graphics library</strong>, it adheres to the <strong>Model-View-Controller (MVC)</strong> design pattern for clear separation of logic, rendering, and control. The project is fully <strong>open-source</strong>.
</p>

---

<div align="center">

<h2>🌟 Supported Platforms</h2>

<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux" />
<img src="https://img.shields.io/badge/macOS-000000?style=for-the-badge&logo=apple&logoColor=white" alt="macOS" />
<img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows" />

</div>

---

<h2 align=center>🎮 Features</h2>

<ul style="list-style-type: none; text-align: left; display: inline-block;">
  <li>✅ <strong>Dynamic Gameplay:</strong> Racket movement using the mouse, with responsive ball physics.</li>
  <li>✅ <strong>Challenging Levels:</strong> Multiple levels loaded from `.txt` files, featuring unique designs.</li>
  <li>✅ <strong>Score Tracking:</strong> Tracks your score and saves the best score locally.</li>
  <li>✅ <strong>Diverse Bricks:</strong> Various brick colors with different point values.</li>
  <li>✅ <strong>Special Bricks:</strong> Silver and gold bricks with unique properties.</li>
  <li>✅ <strong>Game Bonuses:</strong> Collect bonuses to gain extra lives, expand the racket, and more.</li>
</ul>

---

<h2 align=center>🔧 Prerequisites</h2>

<ul style="list-style-type: none; text-align: left; display: inline-block;">
  <li>🔹 <strong>C++20</strong></li>
  <li>🔹 <strong>Allegro 5</strong></li>
  <li>🔹 <strong>g++</strong></li>
  <li>🔹 <strong>make</strong></li>
  <li>🔹 <strong>cmake</strong></li>
</ul>

---

<h2 align=center>🚀 Installation</h2>

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

<h2 align=center>🎲 Usage</h2>

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

<h2 align=center>🎮 Controls</h2>

- `r` : Reset the best score and current score.
- `←` : Move to the previous level.
- `→` : Move to the next level.
- `a` : Replay the current level.
- `q` : Quit the game.
- `Spacebar` : Shoot lasers or release the ball when stuck to the racket.

---

<h2 align=center>🎁 Bonuses </h2>

Collect bonuses by catching them with your racket. Each bonus is marked with a letter inside the corresponding brick:

- **S**: Slow down the ball.
- **E**: Gain an extra life.
- **W**: Expand the racket width.
- **L**: Shoot lasers.
- **T**: Make the ball stick to the racket.
- **B**: Split the ball into three.

---

<h2 align=center>🛠️ Create Your Levels</h2>

Design custom levels in the `ressources/levels` directory using `.txt` files. Name your files numerically (e.g., `1.txt`, `2.txt`). Format each line as follows:

- **X-coordinate**: Horizontal position of the brick.
- **Y-coordinate**: Vertical position of the brick.
- **Color**: Brick color (e.g., `red`, `blue`).
- **Bonus**: (Optional) Specify a bonus (`SlowDown`, `ExtraLife`, etc.).

---

<h2 align=center>📖 Documentation</h2>

For detailed guides and insights, visit the [Arkanoid Wiki](https://github.com/Evr5/arkanoid/wiki).

---

<p></p>

<div align=center>

_Developed with ❤️ by [LuxySs](https://github.com/LuxySs) and [Evr5](https://github.com/Evr5)._  

</div>

</div>
