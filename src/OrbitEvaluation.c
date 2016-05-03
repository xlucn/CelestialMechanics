/**
 * @file OrbitEvaluation.c
 * @brief Solve a two body problem using RKF method
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"

/**
 * Derivatives of x,y,z,vx,vy,vz with respect to time t
 * @param t time
 * @param y 6 components of coordinates and volocities(x,y,z,vx,vy,vz)
 * @return derivatives of x,y,z,vx,vy,vz with respect to time t
 */
double dx(double t, double *y)
{
    return y[3];
}
double dy(double t, double *y)
{
    return y[4];
}
double dz(double t, double *y)
{
    return y[5];
}
double dvx(double t, double *y)
{
    return - mu * y[0] / pow(y[0] * y[0] + y[1] * y[1] + y[2] * y[2], 1.5);
}
double dvy(double t, double *y)
{
    return - mu * y[1] / pow(y[0] * y[0] + y[1] * y[1] + y[2] * y[2], 1.5);
}
double dvz(double t, double *y)
{
    return - mu * y[2] / pow(y[0] * y[0] + y[1] * y[1] + y[2] * y[2], 1.5);
}

int main()
{
    // some parameters
    double step = 864;
    double lo = 0;
    double hi = 2 * 365.2425 * 86400;
    int nfun = 6;
    double TOL = 1e-5;
    double hmax = 864000;
    double hmin = 86.4;
    double *Time = NULL;
    double **res = NULL;

    // some constants used below can be found in "Constants.h"
    mu = G * (MSun + MEarth);
    OrbElem orb1 = orbEarth;
    CoorVol coor = OrbElem2CoorVol(orb1);

    double init[6] = {coor.x, coor.y, coor.z, coor.vx, coor.vy, coor.vz};
    double (*f[6])(double, double*) = {dx, dy, dz, dvx, dvy, dvz};
    int steps = SODERKF(&Time, &res, f, init, lo, hi, nfun, step, TOL, hmax, hmin, 13);

    for(int i = 0; i < steps; i++)
    {
        printf("%.0f ", Time[i]);
        printf("%f %f %f %f %f %f\n",
            res[i][0], res[i][1], res[i][2], res[i][3], res[i][4], res[i][5]);
    }
    free(Time);
    free(res);
    return 0;
}
