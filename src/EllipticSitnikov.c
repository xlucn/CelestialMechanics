/**
 * @file EllipticSitnikov.c
 * @brief Solve the circular Sitnikov Problem
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"

double e;

/**
 * @brief the right function of elliptic Sitnikov Problem
 * @param t time
 * @param y coordinate z and vz
 * @returns derivative of coordinates of time
 *
 * The third object in Sitkoniv Problem is limited in the line vertical to the
 * main plane of the two main bodies, so there is only z and vz in this equation.
 */
double *f(double t, double *y)
{
    double E = SolveKepler(t, e);
    double cosf = (cos(E) - e) / (1 - e * cos(E));
    double r0 = (1 - e * e) / (1 + e * cosf);
    double r = sqrt(pow(r0 / 2, 2) + y[0] * y[0]);

    static double res[2];
    res[0] = y[1];
    res[1] = - y[0] / pow(r, 3);
    return res;
}

int main()
{

    double a = 0;
    double b = 50 * Pi;
    double h0 = Pi / 100;
    double hmax = Pi / 10;
    double hmin = Pi / 1000;
    double TOL = 1e-8;

    e = 0.1;

    int steps;
    double *t;
    double **y;

    int index;
    double z0;
    for(z0 = 0.4, index = 0; z0 < 1.7; z0 += 0.4, index++)
    {
        double y0[] = {z0, 0};

        SODEsol sol = SODERKF(f, y0, a, b, 2, h0, TOL, hmax, hmin, 13);
        steps = sol.step;
        t = sol.t;
        y = sol.y;

        for(int i = 0; i < steps; i++)
        {
            printf("%d %f %f %f\n",index, t[i], y[i][0], y[i][1]);
        }
    }

    free(t);
    free(y);

    return 0;
}
