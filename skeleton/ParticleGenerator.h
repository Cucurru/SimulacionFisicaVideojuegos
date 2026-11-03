#pragma once

#include <random>
#include "Particle.h"
#include "ForceGenerator.h"

class ParticleGenerator
{
public:
	struct ParticleConfig {
		float lifeTime_mean;
		float lifeTime_sigma;

		float pos_mean;
		float pos_sigma;
		Vector3 pos;

		float vel_mean;
		float vel_sigma;
		Vector3 vel;

		float massMean;
		float massSigma;

		Vector4 color;
	};
	
	ParticleGenerator(Vector3 position, Vector3 velocity, int lifeTime, float mass, Vector4 color/*, physx::PxShape* shape*/);

	ParticleGenerator(ParticleConfig config);

	Particle* emitParticle();
	void addForceGenerator(ForceGenerator* fg);

	std::vector<ForceGenerator*> getForceGens() const;

private:

	std::default_random_engine generator;

	std::normal_distribution<float> distrib_v_x;
	std::normal_distribution<float> distrib_v_y;
	std::normal_distribution<float> distrib_v_z;

	std::normal_distribution<float> distrib_p_x;
	std::normal_distribution<float> distrib_p_y;
	std::normal_distribution<float> distrib_p_z;

	std::normal_distribution<float> distrib_lifetime;

	std::normal_distribution<float> distrib_mass;

	//physx::PxShape* partShape;
	Vector4 color;

	std::vector<ForceGenerator*> forceGens;
};

