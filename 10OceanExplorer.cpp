#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


/ Deep Ocean Exploration Algorithims
// Ocean Location Node
struct OceanNode
{
// variables
    int depth;
    string discovery;
    bool explored;


    OceanNode(int d)
    {
        depth = d;
        discovery = "Unknown";
        explored = false;
    }
};


// Sample Priority Queue
struct Sample
{
    string name;
    int importance;


    bool operator<(const Sample& s) const
    {
        return importance < s.importance;
    }
};



class DeepOceanExplorer
{

private:

    vector<OceanNode> oceanMap;

    priority_queue<Sample> discoveries;

    double battery;

    double oxygen;



public:


    DeepOceanExplorer()
    {
        battery = 100;
        oxygen = 100;
    }



    // Create ocean map
    void scanOcean()
    {

        cout<<"Scanning ocean with sonar...\n";


        for(int depth = 100;
            depth <= 5000;
            depth += 500)
        {

            oceanMap.push_back(
                OceanNode(depth)
            );

        }

    }



    // Exploration algorithm
    void explore()
    {

        for(auto &area : oceanMap)
        {

            if(battery <= 10)
            {
                cout<<"Low battery!\n";
                return;
            }


            cout
            <<"Exploring depth "
            <<area.depth
            <<" meters\n";


            area.explored = true;


            battery -= 10;

            oxygen -= 5;


            if(area.depth > 3000)
            {
                discoveries.push(
                    {
                    "Deep Sea Creature",
                    10
                    }
                );
            }

        }

    }



    // Collect important discoveries
    void analyzeSamples()
    {

        while(!discoveries.empty())
        {

            cout
            <<"Discovery: "
            <<discoveries.top().name
            <<endl;


            discoveries.pop();

        }

    }



    void status()
    {

        cout<<"\nExplorer Status\n";

        cout
        <<"Battery: "
        <<battery
        <<"%"<<endl;


        cout
        <<"Oxygen: "
        <<oxygen
        <<"%"<<endl;


        cout
        <<"Mapped Areas: "
        <<oceanMap.size()
        <<endl;

    }

};



int main()
{

    DeepOceanExplorer
    submarine;


    submarine.scanOcean();


    submarine.explore();


    submarine.analyzeSamples();


    submarine.status();


    return 0;
}