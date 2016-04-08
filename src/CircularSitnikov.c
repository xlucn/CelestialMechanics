#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "Constants.h"

double dz(double t, double *y)
{
	return y[1];
}

double dvz(double t, double *y)
{
	return -y[0] / pow(0.25 + y[0] * y[0], 1.5);
}

int main()
{

	double a = 0;
	double b = 20 * pi;
	double h0 = pi / 100;
	double hmax = pi / 10;
	double hmin = pi / 1000;
	double TOL = 1e-3;

    double (*f[])(double, double*) = {dz, dvz};

    double *t;
    double **y;
    double Cj;
	double z;
	double vz;

    int index = 0;
    for(double z0 = 0.5; z0 < 4; z0 += 0.5)
    {
        double y0[] = {z0, 0};
        int steps = SODERKF(&t, &y, f, y0, a, b, 2, h0, TOL, hmax, hmin, 13);

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
