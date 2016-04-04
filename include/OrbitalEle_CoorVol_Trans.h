#ifndef _OCT_H_
#define _OCT_H_

#include <math.h>

// define the orbital elements
typedef struct OrbitalElements{
    double a;       // semimajor axis
    double e;       // eccentricity
    double i;       // inclination
    double Omega;   // longitude of the accending node
    double omega;   // argument of periapsis
    double M;       // mean anomaly
} OrbElem;

// define the coordinate and volocity in Cartesian coordinate system
typedef struct CoordinateVolocity{
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} CoorVol;

// Assume we know the mu of the object in both cases, you have to set the
// value of this variable in main()
double mu;

// Newton method to solve the Kepler equation
double SolveKepler(double M, double e);

// transform from coordinates and volocity to orbital elements
OrbElem CoorVol2OrbElem(CoorVol coor);
CoorVol OrbElem2CoorVol(OrbElem orb);

#endif
