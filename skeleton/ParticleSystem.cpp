#include "ParticleSystem.h"
#include <iostream>

ParticleSystem::ParticleSystem(float limY, float emRate, int maxParts) : limiteY(limY), emissionRate(emRate), maxParticles(maxParts) {

}

ParticleSystem::~ParticleSystem() {
	for (auto p : particles) {
		delete p;
	}
	particles.clear();
}

void ParticleSystem::update(double dt) {
	
	emissionAcc += dt;


	float const timeBetweenEmissions = 1.0f / emissionRate;

	while (emissionAcc >= timeBetweenEmissions) {
		emitParticle();
		emissionAcc -= timeBetweenEmissions;
	}

	for (auto rf : registroFuerzas) {
		//fuerza actualiza la particula vinculadada
		rf.second->updateForce(rf.first, dt);
	}

	//auto it = particles.begin();
	for (auto it = particles.begin(); it != particles.end();) {
		it.operator*()->integrate(dt, Particle::SEMIEULER);

		Vector3 partPos = it.operator*()->getPosition();


		bool expired = it.operator*()->getCurrLife() >= it.operator*()->getMaxLife() || partPos.y < -limiteY;

		if (expired) {
			registroFuerzas.erase(it.operator*());
			delete* it;
			it = particles.erase(it);
		}
		else {
			++it;
		}
	}

}

void ParticleSystem::addParticleGenerator(ParticleGenerator* pg) {
	particleGenerators.push_back(pg);
}

void ParticleSystem::addForceGenerator(ForceGenerator* fg) {
	forceGenerators.push_back(fg);
}

void ParticleSystem::emitParticle() {
	if (particles.size() < maxParticles) {

		for (auto pg : particleGenerators) {
			Particle* p = pg->emitParticle();
			particles.push_back(p);

			auto fgs = pg->getForceGens();
			for (auto fg : fgs) {
				registroFuerzas.insert({ p, fg });
			}
		}
	}
}