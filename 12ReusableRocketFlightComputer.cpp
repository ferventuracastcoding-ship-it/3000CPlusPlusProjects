#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//--------------------------------------
// Flight States
//--------------------------------------

enum class FlightState
{
    PRELAUNCH,
    LIFTOFF,
    ASCENT,
    STAGE_SEPARATION,
    ORBIT,
    REENTRY,
    LANDING_BURN,
    LANDED,
    ABORT
};

//--------------------------------------
// Telemetry
//--------------------------------------

struct Telemetry
{
    double altitude = 0.0;      // meters
    double velocity = 0.0;      // m/s
    double fuel = 100.0;        // %
    double pitch = 90.0;        // degrees
    double temperature = 20.0;  // Celsius
};

//--------------------------------------
// Flight Computer
//--------------------------------------

class FlightComputer
{
private:

    FlightState state;
    Telemetry data;

public:

    FlightComputer()
    {
        state = FlightState::PRELAUNCH;
    }

    //----------------------------------
    // Preflight Check
    //----------------------------------

    bool runPreflight()
    {
        cout << "Running preflight checks...\n";

        if(data.fuel < 95)
        {
            cout << "Fuel too low!\n";
            return false;
        }

        cout << "All systems GO.\n";
        return true;
    }

    //----------------------------------
    // Launch
    //----------------------------------

    void launch()
    {
        if(!runPreflight())
        {
            state = FlightState::ABORT;
            return;
        }

        state = FlightState::LIFTOFF;

        cout << "\nIgnition...\n";
        cout << "Liftoff!\n";
    }

    //----------------------------------
    // Guidance
    //----------------------------------

    void guidance()
    {
        if(state == FlightState::LIFTOFF ||
           state == FlightState::ASCENT)
        {
            data.pitch -= 1.5;

            if(data.pitch < 0)
                data.pitch = 0;
        }
    }

    //----------------------------------
    // Navigation
    //----------------------------------

    void navigation()
    {
        data.altitude += data.velocity;
    }

    //----------------------------------
    // Engine Control
    //----------------------------------

    void engine()
    {
        if(data.fuel <= 0)
            return;

        data.velocity += 25;
        data.fuel -= 1.2;
        data.temperature += 4;
    }

    //----------------------------------
    // Stage Separation
    //----------------------------------

    void stageSeparation()
    {
        if(data.altitude >= 80000 &&
           state == FlightState::ASCENT)
        {
            cout << "\nStage Separation Complete\n";

            state = FlightState::STAGE_SEPARATION;
        }
    }

    //----------------------------------
    // Orbit Detection
    //----------------------------------

    void orbitCheck()
    {
        if(data.altitude >= 200000)
        {
            state = FlightState::ORBIT;

            cout << "\nOrbit Achieved\n";
        }
    }

    //----------------------------------
    // Reentry
    //----------------------------------

    void reentry()
    {
        state = FlightState::REENTRY;

        cout << "\nBeginning Reentry\n";
    }

    //----------------------------------
    // Landing Burn
    //----------------------------------

    void landingBurn()
    {
        state = FlightState::LANDING_BURN;

        while(data.altitude > 0)
        {
            data.altitude -= 1000;

            if(data.velocity > 5)
                data.velocity -= 10;
        }

        state = FlightState::LANDED;
    }

    //----------------------------------
    // Main Flight Loop
    //----------------------------------

    void simulate()
    {
        launch();

        if(state == FlightState::ABORT)
            return;

        state = FlightState::ASCENT;

        while(state == FlightState::ASCENT)
        {
            guidance();

            engine();

            navigation();

            stageSeparation();

            orbitCheck();

            display();

            if(state == FlightState::STAGE_SEPARATION)
                state = FlightState::ASCENT;

            if(state == FlightState::ORBIT)
                break;
        }

        reentry();

        landingBurn();

        display();
    }

    //----------------------------------
    // Telemetry Display
    //----------------------------------

    void display()
    {
        cout << "\n-------------------------\n";

        cout << "Altitude : "
             << data.altitude
             << " m\n";

        cout << "Velocity : "
             << data.velocity
             << " m/s\n";

        cout << "Fuel     : "
             << data.fuel
             << "%\n";

        cout << "Pitch    : "
             << data.pitch
             << " deg\n";

        cout << "Temp     : "
             << data.temperature
             << " C\n";
    }

};

//--------------------------------------
// Main
//--------------------------------------

int main()
{
    FlightComputer starship;

    starship.simulate();

    return 0;
}