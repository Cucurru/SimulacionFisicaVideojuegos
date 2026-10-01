#include "Particle.h"

Particle::Particle(Vector3& pos, Vector3& vel) : p(pos), v(vel), a(Vector3(1.0f,1.0f,1.0f)), d(1.0f), pAnt(pos) {
	
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	
	renderItem = new RenderItem(shape, &p, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
}

Particle::Particle(Vector3& pos, Vector3& vel, Vector3& accel, double damping) : p(pos), v(vel), a(accel), d(damping) {
	
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	
	renderItem = new RenderItem(shape, &p, Vector4(1.0f, 1.0f, 1.0f, 1.0f));
}

Particle::~Particle() {
	
	if (renderItem) {
		renderItem->release();
		renderItem = nullptr;
	}

}

void Particle::integrate(double t, Integer i) {

	//Euler
	if (i == Integer::EULER) {
		p.p += v * t;
		v += a * t;
	}
	//Euler semiimplicito
	else if (i == Integer::SEMIEULER) {
		v += a * t;
		p.p += v * t;
	}
	//Verlet
	else if (i == Integer::VERLET) {
		Vector3 pAct = p.p;
		p.p = 2 * p.p - pAnt + a * pow(t, 2);
		pAnt = pAct;
	}
	//actualizacion velocidad con damping
	v = v * pow(d, t);
}

void Particle::changeAccel(Vector3& accel) {
	a = accel;
}

void Particle::changeDamping(double& damping) {
	d = damping;
}

void Particle::changeColor(Vector4& color) {
	renderItem->color = color;
}

void Particle::changeShape(physx::PxShape* shape) {
	auto oldShape = renderItem->shape;
	renderItem->shape = shape;
	oldShape->release();
}

Vector3& Particle::getAccel() {
	return a;
}