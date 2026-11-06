#pragma once

#include "Particle.h"

class ForceGenerator
{
public:
	ForceGenerator();

	virtual void updateForce(Particle* p, double dt);

	virtual void activate();

	bool isActive() const;

protected:
	bool active;
};

