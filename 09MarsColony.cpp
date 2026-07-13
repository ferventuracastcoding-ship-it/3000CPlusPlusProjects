#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;


// =======================
// Resource System
// Mars Recources
// =======================

class ResourceManager
{

private:

    unordered_map<string,int> resources;


public:

    void add(string name,int amount)
    {
        resources[name] += amount;
    }


    bool consume(string name,int amount)
    {

        if(resources[name] >= amount)
        {
            resources[name] -= amount;
            return true;
        }

        return false;
    }



    void display()
    {

        cout<<"\nResources:\n";

        for(auto r:resources)
        {
            cout
            <<r.first
            <<" : "
            <<r.second
            <<endl;
        }

    }

};



// =======================
// Robot Worker
// =======================

class Robot
{

public:

    string name;
    string job;


    Robot(string n,string j)
    {
        name=n;
        job=j;
    }



    void work()
    {
        cout
        <<name
        <<" is working as "
        <<job
        <<endl;
    }

};



// =======================
// Mission Priority Queue
// =======================

struct Mission
{

    string name;
    int priority;


    bool operator<(const Mission& m)const
    {
        return priority < m.priority;
    }

};



// =======================
// Mars Colony
// =======================

class MarsColony
{

private:

    string name;

    int population;

    int oxygen;

    int energy;


    vector<Robot> robots;

    priority_queue<Mission> missions;


    ResourceManager storage;



public:


    MarsColony(string n)
    {
        name=n;

        population=10;

        oxygen=100;

        energy=100;
    }



    void addRobot(Robot r)
    {
        robots.push_back(r);
    }



    void addResource(
        string item,
        int amount
    )
    {
        storage.add(item,amount);
    }



    void addMission(
        string mission,
        int priority
    )
    {
        missions.push(
            {mission,priority}
        );
    }





    void processMission()
    {

        if(!missions.empty())
        {

            cout
            <<"\nMission Started: "
            <<missions.top().name
            <<endl;


            missions.pop();

        }

    }





    void simulateDay()
    {

        cout
        <<"\n--- Mars Day Simulation ---\n";


        oxygen -= 5;

        energy -= 10;



        if(storage.consume(
            "Food",
            population))
        {
            cout
            <<"Food consumed\n";
        }
        else
        {
            cout
            <<"WARNING: Food shortage\n";
        }



        for(auto &robot:robots)
        {
            robot.work();
        }



        if(oxygen < 30)
        {
            cout
            <<"WARNING: Oxygen low\n";
        }


        if(energy < 30)
        {
            cout
            <<"WARNING: Energy low\n";
        }

    }





    void status()
    {

        cout
        <<"\n===== "
        <<name
        <<" =====\n";


        cout
        <<"Population: "
        <<population
        <<endl;


        cout
        <<"Oxygen: "
        <<oxygen
        <<" %\n";


        cout
        <<"Energy: "
        <<energy
        <<" %\n";


        storage.display();

    }

};





// =======================
// Main Program
// =======================

int main()
{


    MarsColony mars(
        "Olympus Mons Colony"
    );



    // Resources

    mars.addResource(
        "Food",
        500
    );


    mars.addResource(
        "Water",
        1000
    );


    mars.addResource(
        "Iron",
        3000
    );



    // Robots

    mars.addRobot(
        Robot(
            "Rover-01",
            "Mining"
        )
    );


    mars.addRobot(
        Robot(
            "Bot-02",
            "Farming"
        )
    );



    // Missions

    mars.addMission(
        "Repair Solar Reactor",
        10
    );


    mars.addMission(
        "Explore Ice Cave",
        5
    );



    mars.processMission();


    mars.simulateDay();


    mars.status();



    return 0;
}