
# Snake Game in C++

This repository contains a simple command-line Snake Game implemented in C++. The game is designed for beginner programmers to learn about essential programming concepts such as arrays, loops, functions, enums, and game logic.

## Game Description
In this Snake Game:  
- The player controls the snake's movement using the keyboard (`W`, `A`, `S`, `D`).  
- The goal is to eat the fruit (`#`) to grow the snake and increase the score.  
- The game ends if the snake collides with the wall or itself.  

## How to Run the Game

### Prerequisites
1. A C++ compiler (e.g., Visual Studio, Code::Blocks, GCC, or any online compiler).
2. (Optional) Git installed on your computer.

### Steps to Run Locally
1. **Clone the Repository**  
   Open a terminal and run the following command:  
   ```bash
   git clone https://github.com/sudipfgcu/programming1_snakegame.git
   cd snake-game-cpp
   ```

2. **Compile the Code**  
   Use a C++ compiler to compile the code:  
   ```bash
   g++ snake_game.cpp -o snake_game
   ```

3. **Run the Game**  
   Execute the compiled program:  
   ```bash
   ./snake_game
   ```

4. **Play the Game**  
   - Control the snake using the keyboard:  
     - `W`: Move Up  
     - `A`: Move Left  
     - `S`: Move Down  
     - `D`: Move Right  
   - Press `X` to exit the game.

## Features
1. Simple ASCII graphics for easy visualization in the terminal.
2. Adjustable difficulty levels:
   - Easy
   - Medium
   - Hard  
   (Set at the beginning of the game.)
3. Score tracking to compete with yourself or others.

## Code Concepts
This code demonstrates the following C++ concepts:
- **Control Structures**: Loops (`for`, `while`), conditionals (`if`, `switch`).  
- **Enums**: Representing snake directions.  
- **Arrays**: Managing the snake's tail.  
- **Functions**: Game logic split into modular functions (e.g., rendering, input handling, updating game state).  
- **Console I/O**: Using `cout` and `cin` for interactions.  
- **Keyboard Input Handling**: Using `_kbhit()` and `_getch()` from `<conio.h>`.  
- **Basic Graphics**: Drawing walls, the snake, and food with ASCII characters.  

## Try It Yourself
This game is beginner-friendly and can be customized! Here are some ideas:  
1. Add new obstacles to the game.  
2. Change the snake's appearance.  
3. Introduce new game mechanics like power-ups or penalties.  

## Contributing
If you'd like to contribute or suggest improvements:  
1. Fork the repository.  
2. Make your changes.  
3. Submit a pull request.  

## License
This project is open-source and free to use for educational purposes.

## Credits
Developed as a class project to help students learn programming basics in C++.
