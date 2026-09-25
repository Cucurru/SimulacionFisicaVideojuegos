#include "Particle.h"

Particle::Particle(Vector3 pos, Vector3 vel) : p(pos), v(vel), a(Vector3(1.0f,1.0f,1.0f)) {
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	renderItem = new RenderItem(shape, &p, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
}

Particle::~Particle() {
	if (renderItem) {
		renderItem->release();
		renderItem = nullptr;
	}

}

void Particle::integrate(double t) {

	//Euler
	p.p += v * t;
	v += a * t;

}