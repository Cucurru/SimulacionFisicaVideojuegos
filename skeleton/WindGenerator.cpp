#include "WindGenerator.h"

WindGenerator::WindGenerator(Vector3& v, float u, float u2, const Vector3& minBounds, const Vector3& maxBounds)
	: ForceGenerator(), v_wind(v), k1(u), k2(u2), minBounds(minBounds), maxBounds(maxBounds) {

}

void WindGenerator::updateForce(Particle* p, double dt) {

	/*if (!isInsideVolume(p->getPosition())) {
		return;
	}*/

	Vector3 v_particle = p->getVel();

	Vector3 v_rel = v_particle - v_wind;// - v_particle;

	Vector3 f = v_rel * -(k1 +k2 * v_rel.magnitude());

	p->addForce(f);

}

bool WindGenerator::isInsideVolume(const Vector3& pos) const {
	return (pos.x >= minBounds.x && pos.x <= maxBounds.x &&
		pos.y >= minBounds.y && pos.y <= maxBounds.y &&
		pos.z >= minBounds.z && pos.z <= maxBounds.z);
}