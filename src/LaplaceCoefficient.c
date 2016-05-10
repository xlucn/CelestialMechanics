/**
 * @file LaplaceCoefficient.c
 * @brief Calculate the Laplace coefficient in perturbation function expansion
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NR.h"
#include "Constants.h"

int j; /**< the dummy index */
double k; /**< the index in series expansion */
double alpha; /**< the ratio of two semimajor axis */

/**
 * @brief The integrand of the integral in Laplace coefficient
 * @param psi the integral viriable
 * @returns The integrand
 */
double F(double psi)
{
    return cos(j * psi) / pow(1 - 2 * alpha * cos(psi) + alpha * alpha, k);
}

/**
 * @brief
 * @param arg_alpha the dummy index
 * @param arg_j the index in series expansion
 * @param arg_k the ratio of two semimajor axis
 * @returns Laplace coefficient
 */
double LaplaceCoefficient(double arg_alpha, int arg_j, double arg_k)
{
    alpha = arg_alpha;
    j = arg_j;
    k = arg_k;
    return AdaptiveSimpsonInt(F, 0, 2 * Pi, 1e-9) / Pi;
}

int main()
{
    double b1 = LaplaceCoefficient(0.545593441, 1, 1.5);
    double b2 = LaplaceCoefficient(0.545593441, 2, 1.5);
    printf("%.8lf\n%.8lf\n", b1, b2);
    return 0;
}
