#include "ParticleGenerator.h"

#include "GravityGenerator.h"

ParticleGenerator::ParticleGenerator(Vector3 position, Vector3 v, int lifeTime, float m, float emRate, int maxParts, float limY,
	Vector4 clr, float partScale, physx::PxGeometry shape)
	: generator(), distrib_p_x(position.x, 0.5f), distrib_p_y(position.y, 0.5f), distrib_p_z(position.z, 0.5f), distrib_v_x(v.x, 0.5f), distrib_v_y(v.y, 0.5f), distrib_v_z(v.z, 0.5f), distrib_lifetime(lifeTime, 0.5f), distrib_mass(m, 0.5f), maxParticles(maxParts), emissionRate(emRate), limiteY(limY), color(clr), scale(partScale), partShape(shape), gravGen(new GravityGenerator())
{

}

ParticleGenerator::~ParticleGenerator() {
	
	for (auto p : particles) {
		delete p.p;
	}
	particles.clear();
}

void ParticleGenerator::update(double dt) {

	emissionAcc += dt;

	float const timeBetweenEmissions = 1.0f / emissionRate;

	while (emissionAcc >= timeBetweenEmissions) {
		emitParticle();
		emissionAcc -= timeBetweenEmissions;
	}

	for (auto rf : registroFuerzas) {
		rf.second->updateForce(rf.first, dt);
	}

	for (auto it = particles.begin(); it != particles.end(); ) {
		it->p->integrate(dt, Particle::SEMIEULER);

		it->currLife += dt;

		Vector3 const partPos = it->p->getPosition();

		bool expired = false;
		if (it->currLife >= it->maxLife || partPos.y < -limiteY)
			expired = true;

		if (expired) {
			registroFuerzas.erase(it->p);
			delete it->p;
			it = particles.erase(it);
		}
		else {
			++it;
		}
	}
}

void ParticleGenerator::emitParticle() {

	if (particles.size() < maxParticles) {
		Vector3 p(distrib_p_x(generator), distrib_p_y(generator), distrib_p_z(generator));

		float vx, vy, vz;
		vx = distrib_v_x(generator);
		vy = distrib_v_y(generator);
		vz = distrib_v_z(generator);
		Vector3 velocity(vx, vy, vz);

		Vector3 grav(0.0f, -10.0f, 0.0f);

		double const damping = 0.98;

		float lifeT = distrib_lifetime(generator);

		float m = distrib_mass(generator);

		Particle* part = new Particle(p, velocity, damping, m);
		part->changeColor(color);
		particles.push_back({ part, 0.0f, lifeT });

		registroFuerzas.insert({part, gravGen });
	}
}