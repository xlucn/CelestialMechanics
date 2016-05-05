#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"
double  mu = G * (MEarth + MSun);

double *f(double t, double *orb)
{
    double c = 1e-3 * G * MSun * orbEarth.a * AU;
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
    printf("%e %e %e %e %e %e\n",
            res[0], res[1], res[2], res[3], res[4], res[5]);
    return res;
}

int main()
{

    OrbElem earth = orbEarth;

    double y0[] = {earth.a * AU, earth.e, earth.i * Pi / 180, earth.Omega * Pi / 180, earth.omega * Pi / 180, earth.M * Pi / 180};
    double a = 0;
    double b = 100 * secondsperyear;
    int m = 6;
    double h0 = 86400;
    double TOL = 1e-3;
    double hmax = 864000;
    double hmin = 8640;
    int n = 13;

    SODEsol sol = SODERKF(f, y0, a, b, m, h0, TOL, hmax, hmin, n);
    int steps = sol.step;
    double *Time = sol.t;
    double **res = sol.y;

    for(int i = 0; i < steps; i++)
    {
        printf("%.0f ", Time[i]);
        printf("%f %f %f %f %f %f\n",
            res[i][0], res[i][1], res[i][2], res[i][3], res[i][4], res[i][5]);
    }

    return 0;
}
