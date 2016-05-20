/**
 * @file Perturbation.c
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"
double  mu = G * (MEarth + MSun);

/**
 * @brief right function of perturbation equation
 * @param t time
 * @param orb array of orbital elements
 * @returns derivative of orbital elements of time
 *
 *
 */
double *f(double t, double *orb)
{
    double c = 1e-3 * G * MSun * orbEarth.a;
    double a = orb[0];
    double e = orb[1];
    double M = orb[5];

    double beta = sqrt(1 - e * e);
    double E = SolveKepler(M, e);
    double sinf = beta * sin(E) / (1 - e * cos(E));
    double cosf = (cos(E) - e) / (1 - e * cos(E));
    double gamma = 1 / (1 + e * cosf);

    double r = a * (1 - e * e) * gamma;
    double R = - 2 * c / (r * r * r);
    double n = sqrt(mu / (a * a * a));

    static double res[6];
    res[0] = 2 * R * e * sinf / (n * beta);
    res[1] = beta * R * sinf / (n * a);
    res[2] = 0;
    res[3] = 0;
    res[4] = -beta * R * cosf / (n * a * e);
    res[5] = n + (1 - e * e) * R * (cosf - 2 * e * gamma) / (n * a * e);
    return res;
}

int main()
{

    OrbElem earth = orbEarth;

    double y0[] = {earth.a, earth.e, earth.i, earth.Omega, earth.omega, earth.M};
    double a = 0.0;
    double b = 10 * secondsperyear;
    double h0 = 86400.0;
    double TOL = 1e-8;
    double hmax = 864000.0;
    double hmin = 8640.0;

    SODEsol sol = SODERKF(f, y0, a, b, 6, h0, TOL, hmax, hmin, 13);

    for(int i = 0; i < sol.step; i++)
    {
        printf("%f ", sol.t[i] / TorbEarth);
        printf("%f %f %f %f %f %f\n",
            sol.y[i][0], sol.y[i][1], sol.y[i][2], sol.y[i][3], sol.y[i][4], sol.y[i][5]);
    }

    return 0;
}
