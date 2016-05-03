#ifndef _OCT_H_
#define _OCT_H_

#include <math.h>

// define the orbital elements
/**
 * @brief the orbital elements of a object
 *
 *
 */
typedef struct OrbitalElements{
    double a;       /**< semimajor axis. unit:AU */
    double e;       /**< eccentricity */
    double i;       /**< inclination. unit:degree */
    double Omega;   /**< longitude of the accending node. unit:degree */
    double omega;   /**< argument of periapsis. unit:degree */
    double M;       /**< mean anomaly. unit:degree */
} OrbElem;

// define the coordinate and velocity in Cartesian coordinate system
/**
 * @brief coordinate and velocity of a object
 *
 *
 */
typedef struct CoordinateVelocity{
    double x; /**< x coordinate. unit:m */
    double y; /**< y coordinate. unit:m */
    double z; /**< z coordinate. unit:m */
    double vx; /**< x velocity. unit:m s^-1 */
    double vy; /**< y velocity. unit:m s^-1 */
    double vz; /**< z velocity. unit:m s^-1 */
} CoorVol;

/**
 * Assume we know the mu of the object in both cases, you have to set the
 * value of this variable in main()
 */
double mu;

/**
 * Newton method to solve the Kepler equation
 */
double SolveKepler(double M, double e);
/**
 * transform from coordinates and velocity to orbital elements
 */
OrbElem CoorVol2OrbElem(CoorVol coor);
CoorVol OrbElem2CoorVol(OrbElem orb);

#endif
