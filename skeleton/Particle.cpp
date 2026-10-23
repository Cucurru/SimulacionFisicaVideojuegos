#include "Particle.h"

Particle::Particle(Vector3& pos, Vector3& vel, double damping, float m) : p(pos), v(vel), a(Vector3(1.0f,1.0f,1.0f)), d(damping), p0(pos), isVerlet(true), forceAccumulator(0.0f,0.0f,0.0f), w(1/m), posOrig(pos), vOrig(vel) {
	
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	
	renderItem = new RenderItem(shape, &p, Vector4(1.0f, 1.0f, 1.0f, 1.0f));

	if (m == 0) w = 0;
}

Particle::Particle(Vector3& pos, Vector3& vel, Vector3& accel, double damping, float m) : p(pos), v(vel), a(accel), d(damping), isVerlet(true), forceAccumulator(0.0f, 0.0f, 0.0f), w(1/m) {
	
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(1.0f));
	
	renderItem = new RenderItem(shape, &p, Vector4(1.0f, 1.0f, 1.0f, 1.0f));

	if (m == 0) w = 0;
}

Particle::~Particle() {
	
	if (renderItem) {
		renderItem->release();
		renderItem = nullptr;
	}

}

void Particle::integrate(double t, Integer i) {

	a = forceAccumulator * w;

	//Euler
	if (i == Integer::EULER) {
		p.p += v * t;
		v += a * t;
		//actualizacion velocidad con damping
		v = v * pow(d, t);
	}
	//Euler semiimplicito
	else if (i == Integer::SEMIEULER) {
		v += a * t;
		//actualizacion velocidad con damping
		v = v * pow(d, t);
		p.p += v * t;
	}
	//Verlet
	else if (i == Integer::VERLET) {
		if (isVerlet) {
			v += a * t;
			//actualizacion velocidad con damping
			v = v * pow(d, t);
			p1 += v * t;
			isVerlet = false;
			p.p = p1;
		}
		else {
			Vector3 pAct = p.p;
			p.p = 2 * p1 - p0 + a * pow(t, 2);
			p0 = p1;
			p1 = p.p;
		}
	}

	clearForce();
}

void Particle::changeAccel(Vector3 const& accel) {
	a = accel;
}

void Particle::changeDamping(double const& damping) {
	d = damping;
}

void Particle::changeColor(Vector4 const& color) {
	renderItem->color = color;
}

void Particle::changeShape(physx::PxShape* shape) {
	physx::PxShape* oldShape = renderItem->shape;
	renderItem->shape = shape;
	oldShape->release();
}

Vector3 Particle::getAccel() const {
	return a;
}

Vector3 Particle::getPosition() const {
	return p.p;
}

void Particle::addForce(Vector3 f) {
	forceAccumulator += f;
}

void Particle::clearForce() {
	forceAccumulator = Vector3(0, 0, 0);
}

float Particle::getMass() const {
	float m = 0;
	if (w != 0) m = 1 / w;

	return m;
}

void Particle::reset() {
	p.p = posOrig;
	v = vOrig;
	clearForce();
}