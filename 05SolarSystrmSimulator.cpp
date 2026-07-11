#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Planet {
    string name;
    double distance;
    double speed;
    double angle;
};


int main() {

    vector<Planet> planets = {

        {"Mercury", 1, 4.7, 0},
        {"Venus", 2, 3.5, 0},
        {"Earth", 3, 3.0, 0},
        {"Mars", 4, 2.4, 0},
        {"Jupiter", 7, 1.3, 0}

    };


    cout << "===== SOLAR SYSTEM SIMULATOR =====\n";


    for(int day = 1; day <= 10; day++) {

        cout << "\nDay " << day << endl;

        for(auto& planet : planets) {

            planet.angle += planet.speed;

            double x =
                planet.distance * cos(planet.angle);

            double y =
                planet.distance * sin(planet.angle);


            cout << planet.name
                 << " Position: ("
                 << x << ", "
                 << y << ")\n";
        }

    }


    return 0;
}
