#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Vec3 {

    double x, y, z;

    Vec3 operator-(const Vec3& v) {
        return {x-v.x, y-v.y, z-v.z};
    }

    double dot(Vec3 v) {
        return x*v.x + y*v.y + z*v.z;
    }
};


bool hitSphere(Vec3 origin, Vec3 direction, Vec3 center, double radius) {

    Vec3 oc = origin - center;

    double a = direction.dot(direction);

    double b = 2.0 * oc.dot(direction);

    double c = oc.dot(oc) - radius * radius;


    double discriminant =
        b*b - 4*a*c;


    return discriminant >= 0;
}


int main() {

    int width = 400;
    int height = 300;


    ofstream image("raytrace.ppm");


    image << "P3\n";
    image << width << " "
          << height
          << "\n255\n";


    Vec3 camera = {0,0,-1};

    Vec3 sphere = {0,0,2};


    for(int y=0; y<height; y++) {

        for(int x=0; x<width; x++) {


            double u =
                (double)x / width * 2 - 1;


            double v =
                (double)y / height * 2 - 1;


            Vec3 ray = {u,v,1};


            int r,g,b;


            if(hitSphere(camera, ray, sphere, 1)) {

                r = 255;
                g = 0;
                b = 0;

            }
            else {

                r = 100;
                g = 180;
                b = 255;

            }


            image << r << " "
                  << g << " "
                  << b << "\n";

        }
    }


    image.close();


    cout << "Ray traced image created!\n";


    return 0;
}
