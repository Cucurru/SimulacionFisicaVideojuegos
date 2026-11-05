#pragma once

#include "Particle.h"
#include "ParticleGenerator.h"
#include "ForceGenerator.h"
#include <unordered_map>


class ParticleSystem
{
public:
	ParticleSystem(float limY = 100.0f, float emRate = 100.0f, int maxParts = 500);
	~ParticleSystem();

	void update(double dt);

	void addParticleGenerator(ParticleGenerator* pg);

	void addForceGenerator(ForceGenerator* fg);

	void emitParticle();

private:
	std::vector<Particle*> particles;
	std::vector<ParticleGenerator*> particleGenerators;
	std::vector<ForceGenerator*> forceGenerators;
	std::unordered_map<Particle*, std::vector<ForceGenerator*>> registroFuerzas;
	//std::unordered_map<ForceGenerator*, Particle*> registroFuerzas;

	float limiteY;

	float emissionRate;
	float emissionAcc = 0.0f;

	int maxParticles;
};

