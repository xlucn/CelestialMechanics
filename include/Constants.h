/**
 * @file Constants.h
 * @brief This file contains some of the constants frequently used in celestial machanics
 *
 * @note ALL THE QUANTITIES IN THIS FILE ARE IN **SI** UNIT!!!
 */
#ifndef _Const_H_
#define _Const_H_

#include "OrbitalEle_CoorVol_Trans.h" /* struct OrbElem */

/**
 * Physical constants
 */
#define Pi 3.14159265358979323846
#define C 299792458.0
#define G 6.673e-11
#define AU 1.49597870691e11

/**
 * Time
 */
#define secondsperyear 31556952.0
#define secondsperhour 3600.0


/**
 * Physical parameters of sun/planets in solar system
 */
/**
 * RPlanet: radius
 */
#define RMercury    2440000.0
#define RVenus      6051840.0
#define REarth      6371010.0
#define RMars       3389920.0
#define RJupiter    69911000.0
#define RSaturn     58232000.0
#define RUranus     25362000.0
#define RNeptune    24624000.0
#define RPluto      1151000.0
/**
 * MPlanet: mass
 */
#define MSun        1.98893e30
#define MMercury    3.302e23
#define MVenus      4.8658e24
#define MEarth      5.9736e24
#define MMars       6.4185e23
#define MJupiter    1.8986e27
#define MSaturn     5.6846e26
#define MUranus     8.6832e25
#define MNeptune    1.0243e26
#define MPluto      1.314e22
/**
 * RhoPlanet: density
 */
#define RhoMercury  5.247
#define RhoVenus    5.204
#define RhoEarth    5.515
#define RhoMars     3.9335
#define RhoJupiter  1.326
#define RhoSaturn   0.6873
#define RhoUranus   1.318
#define RhoNeptune  1.638
#define RhoPluto    2.0
/**
 * TrotPlanet: ratation period
 */
#define TrotMercury (secondsperhour * 1407.509)
#define TrotVenus   (secondsperhour * 5832.444)
#define TrotEarth   (secondsperhour * 23.93419)
#define TrotMars    (secondsperhour * 24.62296)
#define TrotJupiter (secondsperhour * 9.92425 )
#define TrotSaturn  (secondsperhour * 10.65622)
#define TrotUranus  (secondsperhour * 17.24   )
#define TrotNeptune (secondsperhour * 16.11   )
#define TrotPluto   (secondsperhour * 153.28  )
/**
 * TorbPlanet: orbital period
 */
#define TorbMercury (secondsperyear * 0.2408467)
#define TorbVenus   (secondsperyear * 0.6151973)
#define TorbEarth   (secondsperyear * 1.0000174)
#define TorbMars    (secondsperyear * 1.8808476)
#define TorbJupiter (secondsperyear * 11.862615)
#define TorbSaturn  (secondsperyear * 29.447498)
#define TorbUranus  (secondsperyear * 84.016846)
#define TorbNeptune (secondsperyear * 164.79132)
#define TorbPluto   (secondsperyear * 247.92065)

/**
 * the orbital elements below are at the epoch = J2000.0
 */
static const OrbElem orbMercury = {5.790917567e10, 0.20563069, 0.12225805, 0.84354677, 1.35187008, 4.40260770};
static const OrbElem orbVenus   = {1.082089255e11, 0.00677323, 0.05924887, 1.33833051, 2.29568358, 3.17614546};
static const OrbElem orbEarth   = {1.495978871e11, 0.01671022, 0.00000087,-0.19653524, 1.79676742, 1.75343369};
static const OrbElem orbMars    = {2.279366372e11, 0.09341233, 0.03229924, 0.86530876, 5.86501908, 6.20383077};
static const OrbElem orbJupiter = {7.784120267e11, 0.04839266, 0.02278178, 1.75503590, 0.25750326, 0.60046971};
static const OrbElem orbSaturn  = {1.426725413e12, 0.05415060, 0.04336201, 1.98470186, 1.61324169, 0.87169283};
static const OrbElem orbUranus  = {2.870972220e12, 0.04716771, 0.01343659, 1.29555581, 2.98388889, 5.46693286};
static const OrbElem orbNeptune = {4.498252910e12, 0.00858587, 0.03087784, 2.29897719, 0.78489813, 5.32116035};
static const OrbElem orbPluto   = {5.906376272e12, 0.24880766, 0.29917998, 1.92515873, 3.91070271, 4.17009441};

#endif
