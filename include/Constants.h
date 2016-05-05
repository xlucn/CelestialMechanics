#ifndef _Const_H_
#define _Const_H_

#include "OrbitalEle_CoorVol_Trans.h"
/**
 * Physical constants
 */
#define Pi 3.14159265358979
#define C 299792458.0
#define G 6.673e-11
#define AU 1.49597870691e11

/**
 * Time
 */
#define secondsperyear 31556952.0


/**
 * Physical parameters of sun/planets in solar system
 *
 * RPlanet: radius / m
 * MPlanet: mass / kg
 * RhoPlanet: density / kg m^-3
 * TrotPlanet: ratation period / hour
 * TorbPlanet: orbital period / year
 */

#define RMercury 2440000.0
#define RVenus 6051840.0
#define REarth 6371010.0
#define RMars 3389920.0
#define RJupiter 69911000.0
#define RSaturn 58232000.0
#define RUranus 25362000.0
#define RNeptune 24624000.0
#define RPluto 1151000.0
#define MSun 1.98893e30
#define MMercury 3.302e23
#define MVenus 4.8658e24
#define MEarth 5.9736e24
#define MMars 6.4185e23
#define MJupiter 1.8986e27
#define MSaturn 5.6846e26
#define MUranus 8.6832e25
#define MNeptune 1.0243e26
#define MPluto 1.314e22
#define RhoMercury 5.247
#define RhoVenus 5.204
#define RhoEarth 5.515
#define RhoMars 3.9335
#define RhoJupiter 1.326
#define RhoSaturn 0.6873
#define RhoUranus 1.318
#define RhoNeptune 1.638
#define RhoPluto 2.0
#define TrotMercury
#define TrotVenus
#define TrotEarth
#define TrotMars
#define TrotJupiter
#define TrotSaturn
#define TrotUranus
#define TrotNeptune
#define TrotPluto
#define TorbMercury 0.2408467
#define TorbVenus 0.6151973
#define TorbEarth 1.0000174
#define TorbMars 1.8808476
#define TorbJupiter 11.862615
#define TorbSaturn 29.447498
#define TorbUranus 84.016846
#define TorbNeptune 164.79132
#define TorbPluto 247.92065

/**
 * the orbital elements below are at the epoch = J2000.0
 */
static const OrbElem orbMercury = {0.38709893, 0.20563069, 7.00487, 48.33167, 77.45645, 252.25084};
static const OrbElem orbVenus = {0.72333199, 0.00677323, 3.39471, 76.68069, 131.53298, 181.97973};
static const OrbElem orbEarth = {1.00000011, 0.01671022, 0.00005, -11.26064, 102.94719, 100.46435};
static const OrbElem orbMars = {1.52366231, 0.09341233, 1.85061, 49.57854, 336.04084, 355.45332};
static const OrbElem orbJupiter = {5.20336301, 0.04839266, 1.30530, 100.55615, 14.75385, 34.40438};
static const OrbElem orbSaturn = {9.53707032, 0.05415060, 2.48446, 113.71504, 92.43194, 49.94432};
static const OrbElem orbUranus = {19.19126393, 0.04716771, 0.76986, 74.22988, 170.96424, 313.23218};
static const OrbElem orbNeptune = {30.06896348, 0.00858587, 1.76917, 131.72169, 44.97135, 304.88003};
static const OrbElem orbPluto = {39.48168677, 0.24880766, 17.14175, 110.30347, 224.06676, 238.92881};

#endif
