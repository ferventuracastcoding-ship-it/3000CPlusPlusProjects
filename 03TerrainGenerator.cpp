#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


const int SIZE = 20;


int main() {

    srand(time(nullptr));


    int terrain[SIZE][SIZE];


    cout << "===== TERRAIN GENERATOR =====\n";


    // Generate terrain heights

    for(int y=0; y<SIZE; y++) {

        for(int x=0; x<SIZE; x++) {

            terrain[y][x] =
                rand() % 10;

        }
    }



    // Display terrain

    for(int y=0; y<SIZE; y++) {


        for(int x=0; x<SIZE; x++) {


            int height =
                terrain[y][x];


            if(height < 3)
                cout << "~";   // Water

            else if(height < 6)
                cout << ".";   // Grass

            else
                cout << "^";   // Mountains


        }

        cout << endl;
    }



    return 0;
}
