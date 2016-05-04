#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Constants.h"
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"

double mu;

static double cosffun(double *orb)
{
    double E = SolveKepler(orb[5], orb[1]);
    return (cos(E) - orb[1]) / (1 - orb[1] * cos(E));
}

static double sinffun(double *orb)
{
    double E = SolveKepler(orb[5], orb[1]);
    return sqrt(1 - orb[1] * orb[1]) * sin(E) / (1 - orb[1] * cos(E));
}

static double Rfun(double *orb)
{
    double cosf = cosffun(orb);
    double r = orb[0] * (1 - orb[1] * orb[1]) / (1 + orb[1] * cosf);
    return 2 * c / (r * r * r);
}

double da(double *orb, double t)
{
    double R = Rfun(orb);
    double n = sqrt(mu / (orb[0] * orb[0] * orb[0]));
    return 2 * R * orb[1] * sinf / (n * sqrt(1 - orb[1] * orb[1]));
}

double de(double *orb, double t)
{
    double R = Rfun(orb);
    double sinf = sinffun(orb);
    double n = sqrt(mu / (orb[0] * orb[0] * orb[0]));
    return sqrt(1 - orb[1] * orb[1]) * R * sinf / (n * orb[0]);
}

double di(double *orb, double t)
{
    return 0;
}

double dOmege(double *orb, double t)
{
    return 0;
}

double domega(double *orb, double t)
{
    double R = Rfun(orb);
    double n = sqrt(mu / (orb[0] * orb[0] * orb[0]));
    double cosf = cosffun(orb);
    return -sqrt(1 - orb[1] * orb[1]) * R * cosf / (n * orb[0] * orb[1]);
}
double dM(double *orb, double t)
{
    double R = Rfun(orb);
    double n = sqrt(mu / (orb[0] * orb[0] * orb[0]));
    double cosf = cosffun(orb);
    double gamma = 1 / (1 + orb[1] * cosf);
    return n + (1 - orb[1] * orb[1]) * R * (cosf - 2 * gamma * orb[1]) / (n * orb[0] * orb[1]);
}

int main()
{
    return 0;
}
