/**
 * @file CircularSitnikov.c
 * @brief Solve the circular Sitnikov Problem
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "Constants.h"

/**
 * @brief the right function of Circular Sitnikov Problem
 * @param t time
 * @param y coordinate z and vz
 * @returns derivative of coordinates of time
 *
 * The third object in Sitkoniv Problem is limited in the line vertical to the
 * main plane of the two main bodies, so there is only z and vz in this equation.
 */
double *f(double t, double *y)
{
    static double res[2];
    res[0] = y[1];
    res[1] = -y[0] / pow(0.25 + y[0] * y[0], 1.5);
    return res;
}

int main()
{

    double a = 0;
    double b = 20 * Pi;
    double h0 = Pi / 100;
    double hmax = Pi / 10;
    double hmin = Pi / 1000;
    double TOL = 1e-3;

    int steps;
    double *t;
    double **y;
    double Cj;
    double z;
    double vz;

    int index = 0;
    for(double z0 = 0.5; z0 < 4; z0 += 0.5)
    {
        double y0[] = {z0, 0};
        SODEsol sol = SODERKF(f, y0, a, b, 2, h0, TOL, hmax, hmin, 13);
        steps = sol.step;
        t = sol.t;
        y = sol.y;

        for(int i = 0; i < steps; i++)
        {
            z = y[i][0];
            vz = y[i][1];
            Cj = 2.0 / sqrt(0.25 + z * z) - (vz * vz);
            printf("%d %f %f %f %.10f\n", index, t[i], z, vz, Cj);
        }
        index++;
    }

    free(t);
    free(y);

    return 0;
}
