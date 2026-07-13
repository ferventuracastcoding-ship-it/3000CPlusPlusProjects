#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;


// ===============================
// Map Node for A*
// ===============================

struct Node
{
    int x;
    int y;

    double g;
    double h;


    double f() const
    {
        return g+h;
    }


    bool operator>(const Node& n) const
    {
        return f() > n.f();
    }

};



// ===============================
// Terrain System
// ===============================

class LunarTerrain
{

private:

    vector<vector<int>> map;


public:


    LunarTerrain()
    {

        map =
        {
            {0,0,0,1,0},
            {0,1,0,1,0},
            {0,1,0,0,0},
            {0,0,0,1,0},
            {0,0,0,0,0}
        };

    }



    bool safe(
        int x,
        int y
    )
    {

        if(x<0 || y<0)
            return false;


        if(x>=5 || y>=5)
            return false;


        // 1 = crater/rock

        return map[x][y]==0;

    }


};




// ===============================
// A* Lunar Navigation
// ===============================

class LunarNavigationAI
{

private:

LunarTerrain terrain;



double heuristic(
Node a,
Node b
)
{

return abs(a.x-b.x)
+
abs(a.y-b.y);

}




public:



vector<Node> findPath(
Node start,
Node goal
)
{

priority_queue<
Node,
vector<Node>,
greater<Node>
> open;



open.push(start);



vector<Node> path;



while(!open.empty())
{

Node current =
open.top();

open.pop();



if(current.x==goal.x &&
current.y==goal.y)
{

path.push_back(current);

return path;

}




vector<pair<int,int>> moves =
{
{1,0},
{-1,0},
{0,1},
{0,-1}
};



for(auto move:moves)
{

int nx =
current.x + move.first;


int ny =
current.y + move.second;



if(terrain.safe(nx,ny))
{


Node next;


next.x=nx;
next.y=ny;


next.g=current.g+1;


next.h =
heuristic(
next,
goal
);



open.push(next);


}

}


}


return path;

}


};



// ===============================
// Sensor Fusion
// ===============================

class SensorFusion
{

public:


void update()
{

cout
<<"Combining:\n";

cout
<<"- IMU\n";

cout
<<"- Camera\n";

cout
<<"- LiDAR\n";

cout
<<"Position Updated\n";

}

};



// ===============================
// Power AI
// ===============================

class PowerManager
{

private:

double battery;


public:


PowerManager()
{
battery=100;
}



void drive()
{

battery-=5;


cout
<<"Battery: "
<<battery
<<"%\n";

}



bool lowPower()
{
return battery < 20;
}


};




// ===============================
// Rover AI
// ===============================

class LunarRover
{

private:

LunarNavigationAI navigation;

SensorFusion sensors;

PowerManager power;



public:


void mission()
{

Node start=
{
0,0,0,0
};


Node target=
{
4,4,0,0
};



cout
<<"Starting lunar mission...\n";



sensors.update();



auto path =
navigation.findPath(
start,
target
);



cout
<<"Path Found:\n";



for(auto node:path)
{

cout
<<"Move to "
<<node.x
<<","
<<node.y
<<endl;


power.drive();

}



if(power.lowPower())
{

cout
<<"Returning to base\n";

}


else
{

cout
<<"Mission Complete\n";

}

}


};




// ===============================
// Main
// ===============================

int main()
{

LunarRover rover;


rover.mission();


return 0;

}