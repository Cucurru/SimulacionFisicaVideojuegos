#pragma once

#include <random>
#include "Particle.h"

struct ParticleData {
	Particle* p;
	float currLife;
	float maxLife;
};

class ParticleGenerator
{
public:
	ParticleGenerator(Vector3 position, Vector3 v, int lifeTime, float emRate = 10.0f, int maxParts = 100, float limY = 200.0f,
		Vector4 clr = { 1.0f,1.0f,1.0f,1.0f }, float partScale = 1.0f, physx::PxGeometry shape = physx::PxSphereGeometry(1.0f));

	~ParticleGenerator();

	void update(double dt);

	void emitParticle();

private:
	//Vector3 p;
	//Vector3 v;
	//Vector3 dir;

	std::default_random_engine generator;

	std::normal_distribution<float> distrib_v_x;
	std::normal_distribution<float> distrib_v_y;
	std::normal_distribution<float> distrib_v_z;

	std::normal_distribution<float> distrib_p_x;
	std::normal_distribution<float> distrib_p_y;
	std::normal_distribution<float> distrib_p_z;

	std::normal_distribution<float> distrib_lifetime;


	//float lifeT;
	float emissionRate;
	float emissionAcc = 0.0f;

	int maxParticles;

	float limiteY;

	std::vector<ParticleData> particles;

	float scale;
	physx::PxGeometry partShape;
	Vector4 color;
};

