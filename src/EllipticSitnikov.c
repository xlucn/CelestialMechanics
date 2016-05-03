#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"

double e;

double dz(double t, double *y)
{
	return y[1];
}

double dvz(double t, double *y)
{
    double E = SolveKepler(t, e);
    double f = atan2(cos(E) - e, sqrt(1 - e * e) * sin(E));
    double r0 = (1 - e * e) / (1 + e * cos(f));
    double r = sqrt(pow(r0 / 2, 2) + y[0] * y[0]);
    return - y[0] / pow(r, 3);
}

int main()
{

	double a = 0;
	double b = 50 * pi;
	double h0 = pi / 100;
	double hmax = pi / 10;
	double hmin = pi / 1000;
	double TOL = 1e-8;

    e = 0.1;
    double (*f[])(double, double*) = {dz, dvz};

    double *t;
    double **y;

    int index;
    double z0;
    for(z0 = 0.4, index = 0; z0 < 1.7; z0 += 0.4, index++)
    {
        double y0[] = {z0, 0};
        int steps = SODERKF(&t, &y, f, y0, a, b, 2, h0, TOL, hmax, hmin, 13);

        for(int i = 0; i < steps; i++)
        {
            printf("%d %f %f %f\n",index, t[i], y[i][0], y[i][1]);
        }
    }

    free(t);
	free(y);

	return 0;
}
