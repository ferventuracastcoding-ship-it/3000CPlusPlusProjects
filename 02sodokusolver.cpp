#include <iostream>

using namespace std;

const int SIZE = 9;

int board[SIZE][SIZE] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

bool isSafe(int row, int col, int num) {

    for(int x = 0; x < SIZE; x++)
        if(board[row][x] == num)
            return false;

    for(int x = 0; x < SIZE; x++)
        if(board[x][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[startRow+i][startCol+j] == num)
                return false;

    return true;
}

bool solveSudoku() {

    int row, col;
    bool empty = false;

    for(row = 0; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            if(board[row][col] == 0) {
                empty = true;
                goto FOUND;
            }
        }
    }

FOUND:

    if(!empty)
        return true;

    for(int num = 1; num <= 9; num++) {

        if(isSafe(row,col,num)) {

            board[row][col] = num;

            if(solveSudoku())
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    if(solveSudoku()) {

        cout << "Solved Sudoku\n\n";

        for(int i=0;i<SIZE;i++) {
            for(int j=0;j<SIZE;j++)
                cout << board[i][j] << " ";

            cout << endl;
        }

    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
