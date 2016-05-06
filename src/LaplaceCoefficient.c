#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "Constants.h"

int j;
double k;
double alpha;
double F(double psi)
{
    return cos(j * psi) / pow(1 - 2 * alpha * cos(psi) + alpha * alpha, k);
}

double LaplaceCoefficient(double arg_alpha, int arg_j, double arg_k)
{
    alpha = arg_alpha;
    j = arg_j;
    k = arg_k;
    return AdaptiveSimpsonInt(F, 0, 2 * Pi, 1e-5) / Pi;
}

int main()
{
    double b1 = LaplaceCoefficient(0.545593441, 1, 1.5);
    double b2 = LaplaceCoefficient(0.545593441, 2, 1.5);
    printf("%lf\n%lf\n", b1, b2);
    return 0;
}
