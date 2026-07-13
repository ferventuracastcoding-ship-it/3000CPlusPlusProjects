/*
    STARSHIP LUNAR ORBIT SIMULATOR
    C++

    Simulation:
    Earth -> Moon -> Lunar Orbit

    Concepts:
    - Classes
    - Physics formulas
    - Loops
    - Simulation time
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


// Constants
const double MOON_RADIUS = 1737.4; // km
const double MOON_GRAVITY = 4902.8; // km^3/s^2



// Starship Class
class Starship
{
public:

    string name;

    double altitude;
    double velocity;
    double angle;

    double fuel;



    Starship(string n)
    {
        name = n;

        // Start 100 km above Moon surface
        altitude = 100;

        // Lunar orbital velocity
        velocity = 1.63;

        angle = 0;

        fuel = 100;
    }



    void telemetry()
    {
        cout << fixed << setprecision(2);

        cout << "\n=========== TELEMETRY ===========\n";

        cout << "Ship: "
             << name << endl;

        cout << "Altitude: "
             << altitude
             << " km\n";


        cout << "Velocity: "
             << velocity
             << " km/s\n";


        cout << "Orbit Angle: "
             << angle
             << " degrees\n";


        cout << "Fuel: "
             << fuel
             << "%\n";


        cout << "=================================\n";
    }



    // Simulate orbit movement
    void orbitMoon()
    {

        for(int time = 0; time < 20; time++)
        {

            // Increase orbital angle
            angle += 18;


            if(angle >= 360)
            {
                angle -= 360;
            }


            // Small gravity variation
            altitude += sin(angle * 3.14159 / 180) * 0.5;


            // Keep stable orbit
            if(altitude < 90)
                altitude = 90;


            if(altitude > 120)
                altitude = 120;



            telemetry();


            cout << "Orbiting Moon...\n";
        }

    }



    // Engine burn adjustment
    void engineBurn()
    {
        cout << "\n🔥 Raptor engine burn!\n";


        velocity += 0.05;

        fuel -= 5;


        cout << "Velocity increased.\n";
    }

};



int main()
{

    cout << "=================================\n";
    cout << " STARSHIP MOON ORBIT SIMULATOR\n";
    cout << "=================================\n";



    Starship ship("Starship Lunar Explorer");



    cout << "\n🚀 Entering lunar orbit...\n";


    ship.telemetry();



    // Perform orbit

    ship.orbitMoon();



    // Correction burn

    ship.engineBurn();



    cout << "\nFinal Orbit Status:\n";

    ship.telemetry();



    cout << "\n🌙 Starship successfully orbiting the Moon!\n";



    return 0;
}
