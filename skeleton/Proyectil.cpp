#include "Proyectil.h"
#include <iostream>

Proyectil::Proyectil(Vector3 pos, double realmass, Vector3 realvel, Vector3 simvel, Vector3 realGravity) : Particle(pos, simvel, realGravity, 0.98, 1.0f) {
	mr = realmass;
	gr = realGravity;
	changeVel(realvel, simvel);
}

//equilibra las energias cineticas para que sean iguales
void Proyectil::changeMass(double realmass) {
	mr = realmass;
	
	ms = mr * pow(vr.magnitude()/vs.magnitude(), 2);
}

//actualiza las velocidades y cambia la gravedad y la masa ajustandose a ello
void Proyectil::changeVel(Vector3 realvel, Vector3 simvel) {
	vr = realvel;
	vs = simvel;

	v = vs;

	Vector3 gs = gr * pow(vs.magnitude() / vr.magnitude(), 2);

	changeAccel(gs);
	changeMass(mr);
}

void Proyectil::changeGravity(Vector3 realGravity) {
	gr = realGravity;
	changeVel(vr, vs);
}

std::pair<Vector3, Vector3> Proyectil::getVelocities() const {
	return { vr, vs };
}

void Proyectil::integrate(double t, Integer i) {

	Particle::integrate(t, i);


}