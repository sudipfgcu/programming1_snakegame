#include <iostream>
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h> // For sleep()
using namespace std;

// height and width of the boundary
const int width = 80;
const int height = 20;

// Snake head coordinates of snake (x-axis, y-axis)
int x, y;
// Food coordinates
int fruitCordX, fruitCordY;
// variable to store the score of the player
int playerScore;
// Array to store the coordinates of snake tail (x-axis, y-axis)
int snakeTailX[100], snakeTailY[100];
// variable to store the length of the snake's tail
int snakeTailLen;
// for storing snake's moving direction
enum snakesDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
// snakesDirection variable
snakesDirection sDir;
// boolean variable for checking game is over or not
bool isGameOver;

// Function to initialize game variables
void GameInit() {
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
}

// Function to clear the console
void ClearScreen() {
    system("clear");
}

// Function for creating the game board & rendering
void GameRender(string playerName) {
    ClearScreen(); // Clear the console

    // Creating top walls with '-'
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= width; j++) {
            if (j == 0 || j == width)
                cout << "|"; // Side walls
            else if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == fruitCordY && j == fruitCordX)
                cout << "#"; // Food
            else {
                bool prTail = false;
                for (int k = 0; k < snakeTailLen; k++) {
                    if (snakeTailX[k] == j && snakeTailY[k] == i) {
                        cout << "o"; // Snake tail
                        prTail = true;
                    }
                }
                if (!prTail)
                    cout << " ";
            }
        }
        cout << endl;
    }

    // Creating bottom walls with '-'
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    cout << playerName << "'s Score: " << playerScore << endl;
}

// Function for updating the game state
void UpdateGame() {
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (sDir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;

    for (int i = 0; i < snakeTailLen; i++) {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }

    if (x == fruitCordX && y == fruitCordY) {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}

// Function to handle non-blocking user input
char GetInput() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// Function to handle user input
void UserInput() {
    if (cin.rdbuf()->in_avail() > 0) {
        switch (GetInput()) {
        case 'a':
            sDir = LEFT;
            break;
        case 'd':
            sDir = RIGHT;
            break;
        case 'w':
            sDir = UP;
            break;
        case 's':
            sDir = DOWN;
            break;
        case 'x':
            isGameOver = true;
            break;
        }
    }
}

// Main function / game looping function
int main() {
    srand(time(0));
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    GameInit();
    while (!isGameOver) {
        GameRender(playerName);
        UserInput();
        UpdateGame();
        usleep(100000); // Sleep for 100 milliseconds
    }

    cout << "Game Over! Final Score: " << playerScore << endl;
    return 0;
}
