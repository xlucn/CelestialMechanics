#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NumericalRecipes.h"
#include "Constants.h"

double mu;

double r1fun(double *y)
{
	return sqrt((y[0] + mu)*(y[0] + mu) + y[1] * y[1] + y[2] * y[2]);
}

double r2fun(double *y)
{
	return sqrt((y[0] + mu - 1)*(y[0] + mu - 1) + y[1] * y[1] + y[2] * y[2]);
}

double Omega(double *y)
{
	return (y[0]*y[0]+y[1]*y[1])/2+(1-mu)/r1fun(y)+mu/r2fun(y);
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
	double r1 = r1fun(y);
	double r2 = r2fun(y);
	return 2*y[4]+y[0]-(1-mu)*(y[0]+mu)/(r1*r1*r1)-(mu)*(y[0]+mu-1)/(r2*r2*r2);
}

double dvy(double t, double *y)
{
	double r1 = r1fun(y);
	double r2 = r2fun(y);
	return -2*y[3]+y[1]*(1-(1-mu)/(r1*r1*r1)-mu/(r2*r2*r2));
}

double dvz(double t, double *y)
{
	double r1 = r1fun(y);
	double r2 = r2fun(y);
	return -y[2]*((1-mu)/(r1*r1*r1)+mu/(r2*r2*r2));
}

int main()
{
	mu = 0.001;

	double a = 0;
	double b = 20 * pi;
	double h0 = pi / 100;
	double hmax = pi / 10;
	double hmin = pi / 1000000;
	double TOL = 1e-12;
	// 模拟线性稳定的L4/L5点附近的情况
	double y0[] = {0.499+0.06, sqrt(3)/2, 0, -0.3, -0.3, 0};

	double (*f[])(double, double*) = {dx, dy, dz, dvx, dvy, dvz};

	double *t;
	double **y;
	int steps = SODERKF(&t, &y, f, y0, a, b, 6, h0, TOL, hmax, hmin, 13);

	double Cj;
	for(int i = 0; i < steps; i++)
	{
		Cj = Omega(y[i])*2-(y[i][3]*y[i][3]+y[i][4]*y[i][4]+y[i][5]*y[i][5]);
		printf("%f ", t[i]);
		printf("%f %f %f %f %f %f %.10f\n",
			y[i][0], y[i][1], y[i][2], y[i][3], y[i][4], y[i][5], Cj);
	}
	free(t);
	free(y);

	return 0;
}
