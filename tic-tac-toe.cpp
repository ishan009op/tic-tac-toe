#include <iostream>
using namespace std;

// Game board
char board[3][3] = {{'1', '2', '3'}, 
                   {'4', '5', '6'}, 
                   {'7', '8', '9'}};

// Function to draw the game board
void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function to check for a win
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

int main() {
    char player = 'X';
    int moves = 0;

    while (moves < 9) {
        drawBoard();
        cout << "Player " << player << "'s turn. Enter your move (1-9): ";
        int move;
        cin >> move;

        // Validate move
        if (move < 1 || move > 9) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        // Update game board
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            moves++;
        } else {
            cout << "Spot already taken! Try again." << endl;
            continue;
        }

        // Check for win
        if (checkWin(player)) {
            drawBoard();
            cout << "Player " << player << " wins!" << endl;
            return 0;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    // Draw game
    drawBoard();
    cout << "It's a draw!" << endl;

    return 0;
}
