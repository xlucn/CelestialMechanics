# Celestial Mechanics

Homework of Fundamental Celestial Mechanics Class. This is a project of source
codes and some pictures I wrote to solve the problems in the textbook.

The textbook is written by Jilin Zhou @ NJU.

## Requirement

In case someone wants to use my code:

**This project need the static library of another project of mine :
[MyRecipes](https://github.com/OliverLew/MyRecipes.git)**

Besides of this, you need those programs/modules installed in your computer:

- gcc
- make
- python
    - numpy
    - matplotlib

## Chapter 2

### Problem 2.6

Transformation between orbital elements and coordinate-velocity of a celestial
body.

**related files:**

[transform.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap2/transform.c)

### Problem 2.7

Use RKF7(8) method to integrate the two-body motion's differential equation for
more than two periods. Check the conservation of energy.

**related files:**

[evaluate.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap2/evaluate.c)

[plotorbit.py](https://github.com/OliverLew/CelestialMechanics/blob/master/chap2/plotorbit.py)


## Chapter 3

### Problem 3.2

Find circular restricted three-body problem orbit using RKF7(8) method. Check
the conservation of C_J.

Plot the contour map of C_J in z=0 plane.

Find at least three kinds of motions.

**related files:**

[circularRTB.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/circularRTB.c)

[orbitplot.py](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/orbitplot.py)

[plotcontour.py](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/plotcontour.py)

### Problem 3.4

Use numerical method to plot the Poincare section among the five Lagrangian
points in circular restricted 3-body problem.

**related files**

[circularRTB.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/circularRTB.c)

[PoincareMapRTB.py](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/PoincareMapRTB.py)

### Problem 3.6

Plot the phase diagram of circular and elliptic [Sitnikov problem](https://en.wikipedia.org/wiki/Sitnikov_problem).

**related files**

[CircularSitnikov.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/CircularSitnikov.c)

[EllipticSitnikov.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/EllipticSitnikov.c)

[plotcontour.py](https://github.com/OliverLew/CelestialMechanics/blob/master/chap3/plotcontour.py)

## Chapter 4

### Problem 4.1

The perturbation potential of two body system is U = - c / r^2, solve the
perturbation equations using numerical method.

**related files**

[Perturbation.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap4/Perturbation.c)

[plotperturbation.py](https://github.com/OliverLew/CelestialMechanics/blob/master/chap4/plotperturbation.py)

### Problem 4.3

Calculate the Laplace coefficient. Refer to the values in equation (4.163) in
the textbook.

**related files**

[LaplaceCoefficient.c](https://github.com/OliverLew/CelestialMechanics/blob/master/chap4/LaplaceCoefficient.c)
