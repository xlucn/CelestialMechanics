#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
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

double CJ(double *y)
{
	return Omega(y) * 2 - (y[3] * y[3] + y[4] * y[4] + y[5] * y[5]);
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

/**
 * Suppose that we initalize the coordinates and velocities that only the x and
 * vy is not 0, like (x0, 0, 0, 0, vy0, 0). So with a certain C_J and x0, the
 * initial value of vy will be determined.
 */
double initvy(double CJ0, double x0, double y0)
{
	return sqrt(pow(x0, 2) + pow(y0, 2) - CJ0
		+ 2 * (1 - mu) / sqrt(pow(x0 + mu, 2) + pow(y0, 2))
		+ 2 * mu / sqrt(pow(x0 + mu - 1, 2) + pow(y0, 2)));
}

int main(int argc, char* argv[])
{
	mu = 0.001;

	double a = 0;
	double b = 1000 * pi;
	double h0 = pi / 100;
	double hmax = pi / 10;
	double hmin = pi / 1000000;
	double TOL = 1e-6;

	// here are some examples of initial values, change x0 and Cj down there to
	// use it.
	//
	// x = 0.26, 	vy = 2.1460379245807788,	C_J = 3.12 :	Quasi-periodic-3
	// x = 0.29, 	vy = 1.9577794196268348,	C_J = 3.12 :	Quasi-periodic
	// x = 0.2693, 	vy = 2.0849580921077813,	C_J = 3.12 :	Periodic
	// x = 0.29,	vy = 1.9730433993996144,	C_J = 3.06 :	Chaotic
	// x = 0.225	Periodic-5
	// x = 0.23		Quasi-periodic-5
	// x = 0.22		Quasi-periodic-5
	// x = 0.35		Quasi-periodic-5
	// x = 0.38		Quasi-periodic-7+
	// x = 0.2, 0.22, 0.26, 0.29, 0.32, 0.35, 0.38, 0.4, 0.41, 0.42, 0.45, 0.53,
	// 0.62, 0.67

	// input the parameters here
	double Cj = 3.001;
	double x0 = -1.9;
	double y0 = 0;
	// input the parameters from the terminal or input here
	if(argc >= 4)
	{
		Cj = atof(argv[1]);
		x0 = atof(argv[2]);
		y0 = atof(argv[3]);
		if(argc >= 5)
		{
			b = atof(argv[4]) * pi;
		}
	}

	double (*f[])(double, double*) = {dx, dy, dz, dvx, dvy, dvz};

	double *t;
	double **y;
// for(; x0 > -2; x0 -= 0.1)
// {
// 	fprintf(stderr, "x0: %f\n", x0);
	double r0[] = {x0, y0, 0, 0, initvy(Cj, x0, y0), 0};
	int steps = SODERKF(&t, &y, f, r0, a, b, 6, h0, TOL, hmax, hmin, 13);

	for(int i = 0; i < steps; i+=10)
	{
		Cj = Omega(y[i])*2-(y[i][3]*y[i][3]+y[i][4]*y[i][4]+y[i][5]*y[i][5]);
		printf("%f ", t[i]);
		printf("%f %f %f %f %f %f %.10f\n",
			y[i][0], y[i][1], y[i][2], y[i][3], y[i][4], y[i][5], Cj);
	}
// }
	FILE *para;
	// currently this will work when rum make run command in the project root path
	para = fopen("homework/chap3/circularRTBpara.txt", "w");
	fprintf(para, "a %f\n", a);
	fprintf(para, "b %f\n", b);
	fprintf(para, "TOL %e\n", TOL);
	fprintf(para, "mu %f\n", mu);
	fclose(para);

	free(t);
	free(y);

	return 0;
}
