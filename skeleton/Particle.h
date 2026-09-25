#pragma once
#include "RenderUtils.hpp"

class Particle
{
public:
	Particle(Vector3 pos, Vector3 vel);
	~Particle();

	void integrate(double t);

private:
	Vector3 v;
	Vector3 a;
	physx::PxTransform p;
	RenderItem* renderItem = nullptr;

	//damping
	//masa
};

