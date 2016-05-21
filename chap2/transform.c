// Program to transform a set of orbital elements to coordinates and velocity
// in Cartesian coordinate system and vice versa.
#include <stdio.h>
#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"


int main()
{
	mu = G * (MSun + MEarth);
	OrbElem orb1 = orbEarth;
	printf("Initial state:\na:\t%.10e \ne:\t%.10e \ni:\t%.10e \nOmega:\t%.10e \nomega:\t%.10e \nM:\t%.10e\n\n",
		orb1.a, orb1.e, orb1.i, orb1.Omega, orb1.omega, orb1.M);

	CoorVol coor = OrbElem2CoorVol(orb1);
	printf("Transformed to coordinates:\nx:\t%.10e \ny:\t%.10e \nz:\t%.10e \nvx:\t%.10e \nvy:\t%.10e \nvz:\t%.10e\n\n",
		coor.x, coor.y, coor.z, coor.vx, coor.vy, coor.vz);

	OrbElem orb2 = CoorVol2OrbElem(coor);
	printf("Transformed back from orbital elements:\na:\t%.10e \ne:\t%.10e \ni:\t%.10e \nOmega:\t%.10e \nomega:\t%.10e \nM:\t%.10e\n\n",
		orb2.a, orb2.e, orb2.i, orb2.Omega, orb2.omega, orb2.M);

	return 0;
}
