# Celestial Mechanics

Homework of Fundamental Celestial Mechanics Class. This is a project of source
codes and some pictures I wrote to solve the problems in the textbook.

The textbook is written by Jilin Zhou @ NJU.

This project need the static library of another project of mine:MyRecipes.
see https://github.com/OliverLew/MyRecipes.git

## Chapter 2

### Problem 2.6

Transformation between orbital elements and coordinate-velocity of a celestial body.

**main file:**
[src/transform.c](https://github.com/OliverLew/CelestialMechanics/blob/master/src/transform.c)
[src/OrbitalEle_CoorVol_Trans.c](https://github.com/OliverLew/CelestialMechanics/blob/master/src/OrbitalEle_CoorVol_Trans.c)

### Problem 2.7

Use RKF7(8) method to integrate the two-body motion's differential equation for
more than two periods. Check the conservation of energy.

**main file:**
[src/evaluate.c](https://github.com/OliverLew/CelestialMechanics/blob/master/src/evaluate.c)
[homework/chap2/plotorbit.py](https://github.com/OliverLew/CelestialMechanics/blob/master/homework/chap2/plotorbit.py)


## Chapter 3

### Problem 3.2

Find circular restricted three-body problem orbit using RKF7(8) method. Check the
conservation of C_J.
Plot the contour map of C_J in z=0 plane.
Find at least three kinds of motions.

**main file:**
[src/circularRTB.c](https://github.com/OliverLew/CelestialMechanics/blob/master/src/circularRTB.c)
[homework/chap2/orbitplot.py](https://github.com/OliverLew/CelestialMechanics/blob/master/homework/chap2/orbitplot.py)
[homework/chap2/plotcontour.py](https://github.com/OliverLew/CelestialMechanics/blob/master/homework/chap2/plotcontour.py)
