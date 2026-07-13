#include <iostream>

using namespace std;

char board[8][8];


// Create board
void setupBoard()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            board[i][j] = '.';
        }
    }


    // Black pieces
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((i+j)%2==1)
                board[i][j]='B';
        }
    }


    // White pieces
    for(int i = 5; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((i+j)%2==1)
                board[i][j]='W';
        }
    }
}


// Display board
void display()
{
    cout << "\n";

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}


// Move piece
void movePiece(int r1,int c1,int r2,int c2)
{
    board[r2][c2]=board[r1][c1];
    board[r1][c1]='.';
}


int main()
{
    setupBoard();

    int r1,c1,r2,c2;

    char player='W';


    while(true)
    {
        display();


        cout<<"Player "<<player<<" move\n";

        cout<<"From row col: ";
        cin>>r1>>c1;


        cout<<"To row col: ";
        cin>>r2>>c2;


        if(board[r1][c1]==player)
        {
            movePiece(r1,c1,r2,c2);
        }
        else
        {
            cout<<"Invalid move\n";
        }


        if(player=='W')
            player='B';
        else
            player='W';
    }


    return 0;
}
