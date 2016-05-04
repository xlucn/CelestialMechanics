#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"

double *f(double t, double *orb)
{
    double c = 1;
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
    double y0[6] = {earth.a, earth.e, earth.i, earth.Omega, earth.omega, earth.M};
    double a = 0;
    double b = 1000;
    int m = 6;
    double h0 = 1;
    double TOL = 1;
    double hmax = 10;
    double hmin = 0.1;
    int n = 13;

    SODEsol sol = SODERKF(f, y0, a, b, m, h0, TOL, hmax, hmin, n);

    return 0;
}
