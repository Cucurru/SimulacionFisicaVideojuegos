#pragma once

#include "ForceGenerator.h"

class GravityGenerator : public ForceGenerator
{
public:
	GravityGenerator(Vector3& grav = Vector3(0.0f, -10.0f, 0.0f));

	void updateForce(Particle* p, double dt) override;

private:

	Vector3 g;

};

