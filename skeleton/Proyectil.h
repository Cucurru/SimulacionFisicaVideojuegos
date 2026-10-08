#pragma once
#include "Particle.h"

class Proyectil : public Particle
{
public:
	Proyectil(Vector3 pos, double realmass, Vector3 realvel, Vector3 simvel, Vector3 realGravity = Vector3(0.0,-9.8,0.0));

	void changeMass(double realmass);
	void changeVel(Vector3 realvel, Vector3 simvel);
	void changeGravity(Vector3 realGravity);

	std::pair<Vector3, Vector3> getVelocities() const;

	void integrate(double t, Integer i = Integer::EULER) override;

private:
	double mr;
	Vector3 vr;
	double ms;
	Vector3 vs;
	
	Vector3 gr;

	Vector3 y0;
};

