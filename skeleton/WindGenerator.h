#pragma once

#include "ForceGenerator.h"

class WindGenerator : public ForceGenerator
{
public:
	WindGenerator(Vector3& v, float u, float u2, const Vector3& minBounds, const Vector3& maxBounds);

	virtual void updateForce(Particle* p, double dt) override;

protected:

	bool isInsideVolume(const Vector3& pos) const;

	Vector3 v_wind;

	float k1;
	float k2;

	Vector3 minBounds;
	Vector3 maxBounds;
};