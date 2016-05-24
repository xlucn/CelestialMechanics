/**
 * @file SpinOrbitResonance.c
 * @brief Integral and plot Poincare section of spin-orbit resonance motion
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"

double e = 0.03;
double eps = 0.05;

double *fun(double t, double *y)
{
    double E = SolveKepler(t, e);
    double cosf = (cos(E) - e) / (1 - e * cos(E));
    double f = atan2(sqrt(1 - e * e) * sin(E), cos(E) - e);
    double r = (1 - e * e) / (1 + e * cosf);

    static double res[2];
    res[0] = y[1];
    res[1] = - eps / pow(r, 3) * sin(2*(y[0] - f));
    return res;
}

int main()
{
    for(double theta0 = 0; theta0 < 2 * Pi; theta0 += Pi / 2)
        for(double dtheta0 = 0; dtheta0 <= 2.0; dtheta0 += 0.05)
        {
            double y0[] = {theta0, dtheta0};
            SODEsol sol = SODERKF(fun, y0, 0, 100 * Pi, 2, 0.1, 1e-5, 0.2, 0.001, 13);
            for(int i = 0, count = 0; i < sol.step - 1; i++)
            {
                double k;
                double secy[2];
                if(sol.t[i] <= count * Pi && sol.t[i + 1] > count * Pi)
                {
                    k = (count * Pi - sol.t[i]) / (sol.t[i + 1] - sol.t[i]);
                    secy[0] = k * sol.y[i + 1][0] + (1 - k) * sol.y[i][0];
                    secy[0] = fmod(secy[0], 2 * Pi);
                    secy[0] = secy[0] > 0 ? secy[0] : secy[0] + 2 * Pi;
                    secy[1] = k * sol.y[i + 1][1] + (1 - k) * sol.y[i][1];
                    printf("%f %f %f\n", sol.t[i], secy[0], secy[1]);
                    count += 2;
                }
            }
            DisposeSODEsol(sol);
        }
    return 0;
}
