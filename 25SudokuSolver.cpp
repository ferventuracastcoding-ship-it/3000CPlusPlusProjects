#include <iostream>
using namespace std;


#define SIZE 9


// Print Sudoku board
void printBoard(int board[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}


// Check if number is valid
bool isSafe(int board[SIZE][SIZE],
            int row,
            int col,
            int number)
{
    // Row check
    for(int i=0;i<SIZE;i++)
    {
        if(board[row][i] == number)
            return false;
    }


    // Column check
    for(int i=0;i<SIZE;i++)
    {
        if(board[i][col] == number)
            return false;
    }


    // 3x3 box check
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[boxRow+i][boxCol+j] == number)
                return false;
        }
    }


    return true;
}


// Sudoku recursive solver
bool solveSudoku(int board[SIZE][SIZE])
{
    int row;
    int col;


    bool empty = false;


    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            if(board[row][col] == 0)
            {
                empty = true;
                break;
            }
        }


        if(empty)
            break;
    }


    // Completed
    if(!empty)
        return true;



    for(int num=1; num<=9; num++)
    {
        if(isSafe(board,row,col,num))
        {
            board[row][col] = num;


            if(solveSudoku(board))
                return true;


            // Backtrack
            board[row][col] = 0;
        }
    }


    return false;
}


int main()
{
    int board[SIZE][SIZE] =
    {
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


    if(solveSudoku(board))
    {
        cout << "Solved Sudoku:\n";
        printBoard(board);
    }
    else
    {
        cout << "No solution exists";
    }


    return 0;
}