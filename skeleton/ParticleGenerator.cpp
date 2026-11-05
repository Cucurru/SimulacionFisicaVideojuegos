#include "ParticleGenerator.h"

#include <iostream>

ParticleGenerator::ParticleGenerator(Vector3 position, Vector3 velocity, int lifeTime, float mass, Vector4 color/*, physx::PxShape* shape*/) : 
	generator(), distrib_p_x(position.x, 1.0f), distrib_p_y(position.y, 0.5f), distrib_p_z(position.z, 0.5f),
	distrib_v_x(velocity.x, 0.5f), distrib_v_y(velocity.y, 0.5f), distrib_v_z(velocity.z, 0.5f),
	distrib_lifetime(lifeTime, 1.0f), distrib_mass(mass, 2.0f),
	color(color)/*, partShape(shape) */{

}

ParticleGenerator::ParticleGenerator(ParticleConfig config) : 
	generator(), distrib_p_x(config.pos.x+config.pos_mean, config.pos_sigma), distrib_p_y(config.pos.y + config.pos_mean, config.pos_sigma), distrib_p_z(config.pos.z + config.pos_mean, config.pos_sigma),
	distrib_v_x(config.vel.x*config.vel_mean, config.vel_sigma), distrib_v_y(config.vel.y* config.vel_mean, config.vel_sigma), distrib_v_z(config.vel.z* config.vel_mean, config.vel_sigma), 
	distrib_lifetime(config.lifeTime_mean, config.lifeTime_sigma), distrib_mass(config.massMean, config.massSigma), color(config.color)/*, partShape(config.shape)*/ {

}

Particle* ParticleGenerator::emitParticle() {

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
	m = max(m, 0.1f);

	Particle* part = new Particle(p, velocity, damping, m, lifeT);
	part->changeColor(color);

	return part;
}

void ParticleGenerator::addForceGenerator(ForceGenerator* fg) {
	forceGens.push_back(fg);
}

std::vector<ForceGenerator*> ParticleGenerator::getForceGens() const {
	return forceGens;
}