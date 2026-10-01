#pragma once
#include "RenderUtils.hpp"

class Particle
{
public:
	static enum Integer { EULER, SEMIEULER, VERLET };
	Particle(Vector3& pos, Vector3& vel);
	Particle(Vector3& pos, Vector3& vel, Vector3& accel, double damping);
	~Particle();

	void integrate(double t, Integer i = Integer::EULER);

	void changeAccel(Vector3& accel);
	void changeDamping(double& damping);

	void changeColor(Vector4& color);

	void changeShape(physx::PxShape* s);

	Vector3& getAccel();

private:
	Vector3 v;
	Vector3 a;
	physx::PxTransform p;
	Vector3 pAnt;
	RenderItem* renderItem = nullptr;

	//damping
	double d;
	
	//masa
};

