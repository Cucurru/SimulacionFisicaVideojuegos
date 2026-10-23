#pragma once
#include "RenderUtils.hpp"

class Particle
{
public:
	static enum Integer { EULER, SEMIEULER, VERLET };
	Particle(Vector3& pos, Vector3& vel, double damping = 1.0f, float m = 1.0f);
	Particle(Vector3& pos, Vector3& vel, Vector3& accel, double damping, float m);
	~Particle();

	virtual void integrate(double t, Integer i = Integer::EULER);

	void changeAccel(Vector3 const& accel);
	void changeDamping(double const& damping);

	void changeColor(Vector4 const& color);

	void changeShape(physx::PxShape* s);

	Vector3 getAccel() const;

	Vector3 getPosition() const;

	void addForce(Vector3 f);

	void clearForce();

	float getMass() const;

	void reset();

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

	Vector3 forceAccumulator;
	float w; //inverso masa

	Vector3 posOrig;
	Vector3 vOrig;
};

