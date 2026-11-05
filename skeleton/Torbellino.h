#pragma once
#include "WindGenerator.h"

class Torbellino : public WindGenerator
{
public:
	Torbellino(const Vector3& c, float k, float r, float u, float u2);

	void updateForce(Particle* p, double dt) override;

private:
	
	Vector3 center;
	float K;
	float radius;
};

