#include <iostream>
#include <vector>
#include <string>

using namespace std;


 Sonar Mapping Algorithim
// Sonar Detection Point
struct SonarPoint
{
    int x;
    int y;
    int depth;

    string object;
    double distance;
};



class SonarMapper
{

private:

    vector<SonarPoint> oceanMap;


public:


    // Calculate distance from echo
    double calculateDistance(double time)
    {
        double soundSpeed = 1500.0;

        return (soundSpeed * time) / 2;
    }



    // Add sonar scan
    void scan(
        int x,
        int y,
        int depth,
        string object,
        double echoTime
    )
    {

        double distance =
            calculateDistance(echoTime);



        oceanMap.push_back(
            {
                x,
                y,
                depth,
                object,
                distance
            }
        );


        cout
        << "Detected "
        << object
        << " at "
        << distance
        << " meters\n";

    }



    // Display map
    void displayMap()
    {

        cout << "\n=== SONAR MAP ===\n";


        for(auto point : oceanMap)
        {

            cout
            << "Location: ("
            << point.x
            << ", "
            << point.y
            << ", Depth "
            << point.depth
            << "m) ";

            cout
            << "Object: "
            << point.object
            << " Distance: "
            << point.distance
            << "m\n";

        }

    }

};



int main()
{

    SonarMapper submarineSonar;


    // Sonar scans

    submarineSonar.scan(
        10,
        20,
        500,
        "Rock Formation",
        2.5
    );


    submarineSonar.scan(
        15,
        30,
        1200,
        "Shipwreck",
        5
    );


    submarineSonar.scan(
        40,
        50,
        3000,
        "Unknown Object",
        8
    );



    submarineSonar.displayMap();


    return 0;
}