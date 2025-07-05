#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <windows.h>

#define _USE_MATH_DEFINES
#define PI M_PI

using namespace std; 

void usleep(__int64 usec)
{
  HANDLE timer;
  LARGE_INTEGER ft;

  ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

  timer = CreateWaitableTimer(NULL, TRUE, NULL);
  SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
  WaitForSingleObject(timer, INFINITE);
  CloseHandle(timer);
}

class Vector {
public :
    double x, y, z;
    
    Vector& operator+=(const Vector& other) {
        x += other.x; 
        y += other.y; 
        z += other.z; 
        return *this; 
    }

    // double distance(const Vector& other) {
    //     return sqrt( pow(x-other.x, 2) + pow(y-other.y, 2) + pow(z-other.z, 2) );
    // }
};

int width = 160, height = 44; 
double centerPosOffset = 120; 
double screenZ = 40; // screen at z = 40 
int defaultBackground = ' '; 
int xp, yp, idx; 
double ooz; 
Vector rotationAngles; 

char outBuffer[160*44];
double zBuffer[160*44]; 

double rotationX(Vector& p, Vector& r) {
    return cos(r.z)*cos(r.y)*p.x - sin(r.z)*p.y + cos(r.z)*sin(r.y)*p.z ; 
}

double rotationY(Vector& p, Vector& r) {
    return (cos(r.x)*sin(r.z)*cos(r.y)+sin(r.x)*sin(r.y))*p.x + cos(r.x)*cos(r.z)*p.y + (cos(r.x)*sin(r.z)*sin(r.y)-sin(r.x)*cos(r.y))*p.z ;
}

double rotationZ(Vector& p, Vector& r) {
    return (sin(r.x)*sin(r.z)*cos(r.y)-cos(r.x)*sin(r.y))*p.x + sin(r.x)*cos(r.z)*p.y + (sin(r.x)*sin(r.z)*sin(r.y)+cos(r.x)*cos(r.y))*p.z ; 
}

Vector rotationVector(Vector& p, Vector& r) {
    return {rotationX(p, r), rotationY(p, r), rotationZ(p, r)}; 
}

void displayPoint(Vector _p, int ch) {
    Vector p = { rotationX(_p, rotationAngles), rotationY(_p, rotationAngles), rotationZ(_p, rotationAngles) + centerPosOffset }; 

    ooz = 1/p.z; 

    xp = (int)(width / 2 + p.x * screenZ * ooz * 2); 
    yp = (int)(height / 2 + p.y * screenZ * ooz); 

    idx = yp * width + xp; 
    
    if (idx >= 0 && idx < width*height && ooz > zBuffer[idx]) { 
        zBuffer[idx] = ooz; 
        outBuffer[idx] = ch; 
    }
}

double linearIncrement = 0.5; 
double cubeWidth = 35; 

void displayCube() {
    for(double cubeX = -cubeWidth;cubeX < cubeWidth;cubeX += linearIncrement) {
        for (double cubeY = -cubeWidth;cubeY < cubeWidth;cubeY += linearIncrement) {
            displayPoint({cubeX, cubeY, cubeWidth}, '@'); 
            displayPoint({cubeX, cubeWidth, cubeY}, '#'); 
            displayPoint({cubeWidth, cubeX, cubeY}, '$'); 
            displayPoint({cubeX, cubeY, -cubeWidth}, '%'); 
            displayPoint({cubeX, -cubeWidth, cubeY}, '&'); 
            displayPoint({-cubeWidth, cubeX, cubeY}, '.');  
        }
    }
}

void Cube() {
    while(1) {
        memset(outBuffer, defaultBackground, width*height); 
        memset(zBuffer, 0, 8 * width * height); 

        displayCube(); 

        printf("\x1b[H");
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? outBuffer[k] : 10);
        }
        
        rotationAngles += {0.05, 0.05, 0.01};

        usleep(16000);
    }
}

double circle_radius = 15; 
double torus_radius = 40; 
double theta_increment = 0.02;
double phi_increment = 0.02; 
Vector light = {0, 1, -1}; 

void displayDonut() {
    for(double theta = 0; theta <= 2*PI ; theta += theta_increment) {
        double costheta = cos(theta), sintheta = sin(theta); 
        Vector _p = {circle_radius * costheta + torus_radius, 0, circle_radius * sintheta};
        for(double phi=0; phi <= 2*PI; phi += phi_increment) {
            double cosphi = cos(phi), sinphi = sin(phi); 
            Vector p = { _p.x * cosphi, _p.x * sinphi, _p.z} ; 
            
            Vector _normal = {costheta*cosphi, costheta*sinphi, sintheta}; 
            Vector normal = rotationVector(_normal, rotationAngles); 
            double dot = normal.x*light.x + normal.y*light.y + normal.z*light.z; 
            int luminance_index = 8*dot; 

            if (luminance_index >= 0 && luminance_index <= 12) displayPoint(p, ".,-~:;=!*#$@@"[luminance_index]); 
        }
    }
}

void Donut() {
    while(1) {
        memset(outBuffer, defaultBackground, width*height); 
        memset(zBuffer, 0, 8 * width * height); 

        displayDonut(); 

        printf("\x1b[H");
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? outBuffer[k] : 10);
        }
        
        rotationAngles += {0.05, 0.05, 0.01};

        usleep(16000);
    }
}

int main(void) {
    printf("\x1b[2J");

    // Cube(); 
    Donut(); 
}