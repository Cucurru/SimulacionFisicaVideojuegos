#include "ExplosionGenerator.h"

ExplosionGenerator::ExplosionGenerator(const Vector3& center, float K, float R, float tau, float expansionVel)
	: center(center), K(K), R(R), tau(tau), t(0.0f), active(false), ve(expansionVel) {

}

void ExplosionGenerator::trigger() {
	t = 0.0f;
	active = true;
}

void ExplosionGenerator::update(double dt) {
	if (!active) return;

	t += dt;

	if (t > 4.0f * tau) active = false;
}

void ExplosionGenerator::updateForce(Particle* p, double dt) {
	if (!active) return;

	Vector3 d = p->getPosition() - center;

	float r2 = d.x * d.x + d.y * d.y + d.z * d.z;
	float r = sqrt(r2);

	float Rt = ve * t;//min(ve * t, R);
	if (r >= Rt || r < 0.001f) return;

	Vector3 f = d * (K / r2) * exp(-t / tau);
	p->addForce(f);
}