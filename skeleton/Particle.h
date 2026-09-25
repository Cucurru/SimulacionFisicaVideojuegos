#pragma once
#include "RenderUtils.hpp"

class Particle
{
public:
	Particle(Vector3& pos, Vector3& vel);
	Particle(Vector3& pos, Vector3& vel, Vector3& accel);
	~Particle();

	void integrate(double t);

	void changeAccel(Vector3& accel);

	void changeColor(Vector4& color);

	void changeShape(physx::PxShape* s);

	Vector3& getAccel();

private:
	Vector3 v;
	Vector3 a;
	physx::PxTransform p;
	RenderItem* renderItem = nullptr;

	//damping
	//masa
};

