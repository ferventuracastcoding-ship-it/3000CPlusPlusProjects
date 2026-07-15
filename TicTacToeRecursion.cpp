#include <iostream>
using namespace std;

const int SIZE = 3;

// Print the board
void printBoard(char board[SIZE][SIZE]) {
    cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1)
            cout << "--+---+--" << endl;
    }
    cout << endl;
}

// Check rows, columns, and diagonals
bool checkWinner(char board[SIZE][SIZE], char player) {

    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
            return true;
    }

    // Main diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    // Other diagonal
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check for tie
bool boardFull(char board[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return false;

    return true;
}

// Recursive game loop
void playGame(char board[SIZE][SIZE], char player) {

    printBoard(board);

    // Base Case #1: Someone wins
    if (checkWinner(board, 'X')) {
        cout << "Player X Wins!\n";
        return;
    }

    if (checkWinner(board, 'O')) {
        cout << "Player O Wins!\n";
        return;
    }

    // Base Case #2: Tie
    if (boardFull(board)) {
        cout << "It's a Tie!\n";
        return;
    }

    int row, col;

    cout << "Player " << player << "'s turn\n";
    cout << "Enter row (0-2): ";
    cin >> row;
    cout << "Enter column (0-2): ";
    cin >> col;

    // Validate move
    if (row < 0 || row > 2 ||
        col < 0 || col > 2 ||
        board[row][col] != ' ') {

        cout << "Invalid move! Try again.\n";

        // Recursive call without changing player
        playGame(board, player);
        return;
    }

    // Place piece
    board[row][col] = player;

    // Switch player
    char nextPlayer = (player == 'X') ? 'O' : 'X';

    // Recursive call
    playGame(board, nextPlayer);
}

int main() {

    char board[SIZE][SIZE] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };

    playGame(board, 'X');

    return 0;
}