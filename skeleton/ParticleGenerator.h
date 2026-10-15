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
	ParticleGenerator(Vector3 position, /*Vector3 direction, Vector3 initialVel,*/ std::pair<float, float> desvX, std::pair<float, float> desvY, std::pair<float, float> desvZ, bool uniformDistribution, int lifeTime, float emRate = 10.0f, float limY = 200.0f,
		Vector4 clr = { 0.0f,0.0f,0.0f,1.0f }, float partScale = 1.0f, physx::PxShape* shape = nullptr);

	~ParticleGenerator();

	void update(double dt);

	void emitParticle();

private:
	Vector3 p;
	Vector3 v;
	Vector3 dir;

	std::random_device rd;
	std::mt19937 gen;

	bool useUnifDistrib;
	std::uniform_real_distribution<float> unif_x;
	std::uniform_real_distribution<float> unif_y;
	std::uniform_real_distribution<float> unif_z;

	std::normal_distribution<float> gauss_x;
	std::normal_distribution<float> gauss_y;
	std::normal_distribution<float> gauss_z;

	float lifeT;
	float emissionRate;
	float emissionAcc = 0.0f;

	float limiteY;

	std::vector<ParticleData> particles;

	float scale;
	physx::PxShape* partShape;
	Vector4 color;
};

