#ifndef _Const_H_
#define _Const_H_

#include "OrbitalEle_CoorVol_Trans.h"

static double pi = 3.1415926535;
static double G = 6.673e-11;
static double MSun = 1.98893e30;
static double MEarth = 5.97371e24;
static double AU = 1.49597870691e11;

// the orbital elements below are based on the epoch = J2000.0
static OrbElem orbMercury = {0.38709893, 0.20563069, 7.00487, 48.33167, 77.45645, 252.25084};
static OrbElem orbVenus = {0.72333199, 0.00677323, 3.39471, 76.68069, 131.53298, 181.97973};
static OrbElem orbEarth = {1.00000011, 0.01671022, 0.00005, -11.26064, 102.94719, 100.46435};
static OrbElem orbMars = {1.52366231, 0.09341233, 1.85061, 49.57854, 336.04084, 355.45332};
static OrbElem orbJupiter = {5.20336301, 0.04839266, 1.30530, 100.55615, 14.75385, 34.40438};
static OrbElem orbSaturn = {9.53707032, 0.05415060, 2.48446, 113.71504, 92.43194, 49.94432};
static OrbElem orbUranus = {19.19126393, 0.04716771, 0.76986, 74.22988, 170.96424, 313.23218};
static OrbElem orbNeptune = {30.06896348, 0.00858587, 1.76917, 131.72169, 44.97135, 304.88003};
static OrbElem orbPluto = {39.48168677, 0.24880766, 17.14175, 110.30347, 224.06676, 238.92881};

#endif
