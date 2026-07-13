//--------------------------------------
// Navigation System
//--------------------------------------

class NavigationSystem
{
private:

    // Position (meters)
    double posX = 0;
    double posY = 0;
    double altitude = 0;

    // Velocity (m/s)
    double velocityX = 0;
    double velocityY = 0;
    double verticalVelocity = 0;

    // Acceleration (m/s²)
    double accelX = 0;
    double accelY = 0;
    double accelZ = 0;

    // Orientation (degrees)
    double pitch = 90;
    double yaw = 0;
    double roll = 0;

public:

    //----------------------------------
    // Read simulated sensors
    //----------------------------------

    void readIMU()
    {
        accelZ = 25.0;
        accelX = 0.4;
        accelY = 0.1;
    }

    //----------------------------------
    // Update velocities
    //----------------------------------

    void integrateVelocity(double dt)
    {
        velocityX += accelX * dt;
        velocityY += accelY * dt;
        verticalVelocity += accelZ * dt;
    }

    //----------------------------------
    // Update position
    //----------------------------------

    void integratePosition(double dt)
    {
        posX += velocityX * dt;
        posY += velocityY * dt;
        altitude += verticalVelocity * dt;
    }

    //----------------------------------
    // Simulated GPS correction
    //----------------------------------

    void GPSCorrection()
    {
        posX += 0.02;
        posY -= 0.01;
    }

    //----------------------------------
    // Simulated star tracker
    //----------------------------------

    void updateStarTracker()
    {
        yaw += 0.005;
        roll += 0.002;
    }

    //----------------------------------
    // Complete navigation update
    //----------------------------------

    void update(double dt)
    {
        readIMU();
        integrateVelocity(dt);
        integratePosition(dt);
        GPSCorrection();
        updateStarTracker();
    }

    double getAltitude() const
    {
        return altitude;
    }

    double getVelocity() const
    {
        return verticalVelocity;
    }

    double getPitch() const
    {
        return pitch;
    }

    void printStatus()
    {
        cout << "\n=== Navigation ===\n";
        cout << "Altitude : " << altitude << " m\n";
        cout << "Velocity : " << verticalVelocity << " m/s\n";
        cout << "Position : (" << posX << ", " << posY << ")\n";
        cout << "Pitch    : " << pitch << "°\n";
        cout << "Yaw      : " << yaw << "°\n";
        cout << "Roll     : " << roll << "°\n";
    }
};


//--------------------------------------
// Guidance System
//--------------------------------------

class GuidanceSystem
{
private:

    double targetOrbit = 200000;      // meters
    double gravityTurnStart = 1000;
    double gravityTurnEnd = 80000;

public:

    //----------------------------------
    // Gravity Turn
    //----------------------------------

    void gravityTurn(double altitude,
                     double &pitch)
    {
        if(altitude < gravityTurnStart)
            return;

        if(altitude > gravityTurnEnd)
        {
            pitch = 0;
            return;
        }

        double progress =
            (altitude - gravityTurnStart) /
            (gravityTurnEnd - gravityTurnStart);

        pitch = 90 - progress * 90;
    }

    //----------------------------------
    // Throttle Control
    //----------------------------------

    double computeThrottle(double altitude)
    {
        if(altitude < 50000)
            return 100.0;

        if(altitude < 120000)
            return 80.0;

        return 55.0;
    }

    //----------------------------------
    // Orbit Check
    //----------------------------------

    bool reachedOrbit(double altitude)
    {
        return altitude >= targetOrbit;
    }

    //----------------------------------
    // Guidance Update
    //----------------------------------

    void update(double altitude,
                double &pitch)
    {
        gravityTurn(altitude, pitch);

        double throttle =
            computeThrottle(altitude);

        cout << "\n=== Guidance ===\n";
        cout << "Target Orbit : "
             << targetOrbit
             << " m\n";

        cout << "Recommended Pitch : "
             << pitch
             << "°\n";

        cout << "Throttle : "
             << throttle
             << "%\n";
    }
};