#include "OrbitalEle_CoorVol_Trans.h"
#include "Constants.h"

// Newton method to solve the Kepler equation
double SolveKepler(double M, double e)
{
	double E = 0;
	double E0;

	do {
		E0 = E;
		E = E0 - (E0 - e * sin(E0) - M) / (1 - e * cos(E0));
	} while(fabs(E - E0) > 1e-14);

	return E;
}

// transform from coordinates and velocity to orbital elements
OrbElem CoorVol2OrbElem(CoorVol coor)
{
	double x = coor.x;
	double y = coor.y;
	double z = coor.z;
	double vx = coor.vx;
	double vy = coor.vy;
	double vz = coor.vz;

	double r = sqrt(x * x + y * y + z * z); // radius
	double v = sqrt(vx * vx + vy * vy + vz * vz); // speed
	double a = 1 / (2 / r - v * v / mu); // semimajor axis
	double n = sqrt(mu / (a * a * a)); // mean motion
	double Hx = y * vz - z * vy; // angular momentum x component
	double Hy = z * vx - x * vz; // y component
	double Hz = x * vy - y * vx; // z component
	double h = sqrt(Hx * Hx + Hy * Hy + Hz * Hz); //
	double e = sqrt(1 - h * h / mu / a); // eccentricity
	double cosE = (1 - r / a) / e; // eccentric anomaly sin and cos
	double sinE = (x * vx + y * vy + z * vz) / (a * a * n * e);
	double E = atan2(sinE, cosE); // eccentric anomaly
	double M = E - e * sin(E); // mean anomaly
	double i = acos(Hz / h); // inclination
	double Omega = atan2(Hx, -Hy); // longitude of the accending node (2.122)
	double Pz = cos(E) * z / r - sin(E) * vz / n / a;
	double Qz = (sin(E) * z / r + (cos(E) - e) * vz / (n * a)) / sqrt(1 - e * e);
	double omega = atan2(Pz, Qz); // argument of periapsis

	OrbElem orb = {a / AU, e, i * 180 / pi, Omega * 180 / pi, omega * 180 / pi, M * 180 / pi};
	return orb;
}

CoorVol OrbElem2CoorVol(OrbElem orb)
{
	double a = orb.a * AU;
	double e = orb.e;
	double i = orb.i / 180 * pi;
	double Omega = orb.Omega / 180 * pi;
	double omega = orb.omega / 180 * pi;
	double M = orb.M / 180 * pi;

	double E = SolveKepler(M, e);
	double r = a * (1 - e * cos(E));

	// define the ratation matrix from the orbital plane to the reference plane
	double cO = cos(Omega);
	double sO = sin(Omega);
	double co = cos(omega);
	double so = sin(omega);
	double ci = cos(i);
	double si = sin(i);
	double t[3][3] = {
		{cO * co - sO * so * ci, - cO * so - sO * co * ci, sO * si},
		{sO * co + cO * so * ci, - sO * so + cO * co * ci, - cO * si},
		{so * si, co * si, ci}
	};

	double x0 = a * (cos(E) - e);
	double y0 = a * sqrt(1 - e * e) * sin(E);
	double z0 = 0;
	double vx0 = - sqrt(mu / (a * (1 - e * e))) * y0 / r;
	double vy0 = sqrt(mu / (a * (1 - e * e))) * (e + x0 / r);
	double vz0 = 0;

	// rotate tranformation
	double x = t[0][0] * x0 + t[0][1] * y0 + t[0][2] * z0;
	double y = t[1][0] * x0 + t[1][1] * y0 + t[1][2] * z0;
	double z = t[2][0] * x0 + t[2][1] * y0 + t[2][2] * z0;
	double vx = t[0][0] * vx0 + t[0][1] * vy0 + t[0][2] * vz0;
	double vy = t[1][0] * vx0 + t[1][1] * vy0 + t[1][2] * vz0;
	double vz = t[2][0] * vx0 + t[2][1] * vy0 + t[2][2] * vz0;

	CoorVol coor = {x, y, z, vx, vy, vz};
	return coor;
}
