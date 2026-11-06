#pragma once
#include "ForceGenerator.h"

class ExplosionGenerator : public ForceGenerator
{
public:
	ExplosionGenerator(const Vector3& center, float K, float R, float tau, float expansionVel);

	void update(double dt);

	void updateForce(Particle* p, double dt) override;

	void activate() override;

private:
	Vector3 center;
	float K;
	float R;
	float tau;
	float t;
	//bool active;

	float ve;
};

