#pragma once
#include "RenderUtils.hpp"

class Particle
{
public:
	static enum Integer { EULER, SEMIEULER, VERLET };
	Particle(Vector3& pos, Vector3& vel);
	Particle(Vector3& pos, Vector3& vel, Vector3& accel, double damping);
	~Particle();

	virtual void integrate(double t, Integer i = Integer::EULER);

	void changeAccel(Vector3 const& accel);
	void changeDamping(double const& damping);

	void changeColor(Vector4 const& color);

	void changeShape(physx::PxShape* s);

	Vector3 getAccel() const;

protected:
	Vector3 v;
	Vector3 a;
	physx::PxTransform p;
	RenderItem* renderItem = nullptr;

	//damping
	double d;

	bool isVerlet;
	Vector3 p0;
	Vector3 p1;
};

