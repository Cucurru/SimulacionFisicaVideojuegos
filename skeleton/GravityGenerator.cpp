#include "GravityGenerator.h"

GravityGenerator::GravityGenerator(Vector3& grav) : ForceGenerator(), g(grav) {

}

void GravityGenerator::updateForce(Particle* p, double dt) {

	float m = p->getMass();

	Vector3 f = g * m;

	p->addForce(f);

}