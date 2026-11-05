#include "Torbellino.h"

Torbellino::Torbellino(const Vector3& c, float k, float r, float u, float u2) :
	WindGenerator(Vector3(0), u, u2, Vector3(0), Vector3(0)), K(k), center(c), radius(r) {

}
void Torbellino::updateForce(Particle* p, double dt) {

	Vector3 pos = p->getPosition();

	float dist = sqrt(pow(pos.x - center.x, 2) + pow(pos.z - center.z, 2));

	if (dist > radius) {
		return;
	}

	v_wind = K * Vector3(-(pos.z - center.z), 50 - (pos.y - center.y), pos.x - center.x);

	WindGenerator::updateForce(p, dt);
}