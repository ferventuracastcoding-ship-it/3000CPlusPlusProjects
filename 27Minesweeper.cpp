#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;
const int MINES = 15;

char board[SIZE][SIZE];
char hidden[SIZE][SIZE];


// Create empty boards
void initialize()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = '-';
            hidden[i][j] = '0';
        }
    }
}


// Place random mines
void placeMines()
{
    int placed = 0;

    while(placed < MINES)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;


        if(hidden[row][col] != '*')
        {
            hidden[row][col] = '*';
            placed++;
        }
    }
}


// Count mines around a cell
int countMines(int row, int col)
{
    int count = 0;


    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int r = row + i;
            int c = col + j;


            if(r >= 0 && r < SIZE &&
               c >= 0 && c < SIZE)
            {
                if(hidden[r][c] == '*')
                    count++;
            }
        }
    }


    return count;
}


// Generate numbers
void calculateNumbers()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(hidden[i][j] != '*')
            {
                hidden[i][j] =
                    '0' + countMines(i,j);
            }
        }
    }
}


// Display board
void display()
{
    cout << "\n   ";

    for(int i=0;i<SIZE;i++)
        cout << i << " ";

    cout << endl;


    for(int i=0;i<SIZE;i++)
    {
        cout << i << "  ";

        for(int j=0;j<SIZE;j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}


// Reveal cell
bool reveal(int row,int col)
{
    if(hidden[row][col]=='*')
    {
        return false;
    }


    board[row][col]=hidden[row][col];

    return true;
}


// Check victory
bool checkWin()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(board[i][j]=='-' &&
               hidden[i][j]!='*')
            {
                return false;
            }
        }
    }

    return true;
}



int main()
{
    srand(time(0));


    initialize();
    placeMines();
    calculateNumbers();


    int row,col;


    cout<<"=== MINESWEEPER ===\n";
    cout<<"Find all safe spaces!\n";


    while(true)
    {
        display();


        cout<<"\nChoose row: ";
        cin>>row;

        cout<<"Choose column: ";
        cin>>col;


        if(row < 0 || row >= SIZE ||
           col < 0 || col >= SIZE)
        {
            cout<<"Invalid location!\n";
            continue;
        }


        if(!reveal(row,col))
        {
            cout<<"\nBOOM! You hit a mine!\n";

            // Show mines
            for(int i=0;i<SIZE;i++)
            {
                for(int j=0;j<SIZE;j++)
                {
                    if(hidden[i][j]=='*')
                        board[i][j]='*';
                }
            }

            display();

            break;
        }


        if(checkWin())
        {
            display();
            cout<<"\nYou cleared the minefield!\n";
            break;
        }
    }


    return 0;
}
