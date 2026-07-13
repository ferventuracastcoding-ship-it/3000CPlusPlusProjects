#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;

int x, y;
int foodX, foodY;
int score;

int tailX[100], tailY[100];
int tailLength;


enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

Direction dir;


// Setup game
void Setup()
{
    gameOver = false;

    dir = STOP;

    x = width / 2;
    y = height / 2;

    foodX = rand() % width;
    foodY = rand() % height;

    score = 0;

    tailLength = 0;
}


// Draw game screen
void Draw()
{
    system("cls");


    for(int i=0;i<width+2;i++)
        cout<<"#";

    cout<<endl;


    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<"#";


            if(i==y && j==x)
                cout<<"O";

            else if(i==foodY && j==foodX)
                cout<<"F";

            else
            {
                bool print=false;

                for(int k=0;k<tailLength;k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }

                if(!print)
                    cout<<" ";
            }


            if(j==width-1)
                cout<<"#";
        }

        cout<<endl;
    }


    for(int i=0;i<width+2;i++)
        cout<<"#";


    cout<<"\nScore: "<<score;
}


// Keyboard controls
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
                dir = LEFT;
                break;

            case 'd':
                dir = RIGHT;
                break;

            case 'w':
                dir = UP;
                break;

            case 's':
                dir = DOWN;
                break;

            case 'x':
                gameOver=true;
                break;
        }
    }
}


// Game movement
void Logic()
{
    int previousX = tailX[0];
    int previousY = tailY[0];

    tailX[0]=x;
    tailY[0]=y;


    for(int i=1;i<tailLength;i++)
    {
        int tempX=tailX[i];
        int tempY=tailY[i];

        tailX[i]=previousX;
        tailY[i]=previousY;

        previousX=tempX;
        previousY=tempY;
    }



    switch(dir)
    {
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


    // Wall collision
    if(x<0 || x>=width || y<0 || y>=height)
        gameOver=true;


    // Eating food
    if(x==foodX && y==foodY)
    {
        score+=10;

        foodX=rand()%width;
        foodY=rand()%height;

        tailLength++;
    }


    // Snake hits itself
    for(int i=0;i<tailLength;i++)
    {
        if(tailX[i]==x && tailY[i]==y)
            gameOver=true;
    }
}



int main()
{
    Setup();


    while(!gameOver)
    {
        Draw();
        Input();
        Logic();

        Sleep(100);
    }


    cout<<"\nGame Over!";
    return 0;
}
