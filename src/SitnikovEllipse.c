#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"

double mu;
double e;

double F(double t)
{
    double E = SolveKepler(t, e);
    return atan2(cos(E) - e, sqrt(1 - e * e) * sin(E));
}

double dF(double t)
{
    double f = F(t);
    return pow((1 - e * e), -1.5) * pow((1 + e * cos(f)), 2);
}

double ddF(double t)
{
    double f = F(t);
    return -2 * e * pow((1 - e * e), -3) * sin(f) * pow((1 + e * cos(f)), 3);
}

double r0fun(double t)
{
    double f = F(t);
    return (1 - e * e) / (1 + e * cos(f));
}

double r1fun(double t, double *y)
{
    double r0 = r0fun(t);
	return sqrt(pow((y[0] + mu * r0), 2) + y[1] * y[1] + y[2] * y[2]);
}

double r2fun(double t, double *y)
{
    double r0 = r0fun(t);
	return sqrt(pow((y[0] - (1 - mu) * r0), 2) + y[1] * y[1] + y[2] * y[2]);
}

double W(double t, double *y)
{
	return (1 - mu) / r1fun(t, y) + mu / r2fun(t, y);
}

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
    double r0 = r0fun(t);
    double df = dF(t);
    double ddf = ddF(t);
	double r1 = r1fun(t, y);
	double r2 = r2fun(t, y);
    double dWdx = -(1 - mu) * (y[0] + mu * r0) / pow(r1, 3) - mu * (y[0] - (1 - mu) * r0) / pow(r2, 3);
	return dWdx + 2 * df * y[4] + df * df * y[0] + ddf * y[1];
}

double dvy(double t, double *y)
{
    double df = dF(t);
    double ddf = ddF(t);
	double r1 = r1fun(t, y);
	double r2 = r2fun(t, y);
    double dWdy = -(1 - mu) * y[1] / pow(r1, 3) - mu * y[1] / pow(r2, 3);
	return dWdy - 2 * df * y[3] + df * df * y[1] - ddf * y[0];
}

double dvz(double t, double *y)
{
	double r1 = r1fun(t, y);
	double r2 = r2fun(t, y);
    double dWdz = -(1 - mu) * y[2] / pow(r1, 3) - mu * y[2] / pow(r2, 3);
	return dWdz;
}

int main()
{

	double a = 0;
	double b = 23 * pi;
	double h0 = pi / 10;
	double hmax = pi / 10;
	double hmin = pi / 100;
	double TOL = 1e1;

	mu = 0.5;
    e = 0.3;
    double (*f[])(double, double*) = {dx, dy, dz, dvx, dvy, dvz};

    double *t;
    double **y;

    int index;
    double z0;
    for(z0 = 0.5, index = 0; z0 < 0.7; z0 += 0.5, index++)
    {
        double y0[] = {0, 0, 0.5, 0, 0, 0};
        int steps = SODERKF(&t, &y, f, y0, a, b, 6, h0, TOL, hmax, hmin, 13);

        for(int i = 0; i < steps; i++)
        {
            printf("%d ", index);
            printf("%f ", t[i]);
            printf("%f %f %f %f %f %f\n",
            y[i][0], y[i][1], y[i][2], y[i][3], y[i][4], y[i][5]);
        }
    }

    free(t);
	free(y);

	return 0;
}
