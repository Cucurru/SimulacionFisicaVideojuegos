#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator(Vector3 position, /*Vector3 direction, Vector3 initialVel, */std::pair<float, float> desvX, std::pair<float, float> desvY, std::pair<float, float> desvZ, bool uniformDistribution, int lifeTime, float emRate, float limY,
	Vector4 clr, float partScale, physx::PxShape* shape)
	: p(position), /*dir(direction), v(initialVel),*/ gen(rd()),
	unif_x(desvX.first, desvX.second), unif_y(desvY.first, desvY.second), unif_z(desvZ.first, desvZ.second), 
	gauss_x(desvX.first, std::sqrt(desvX.second)), gauss_y(desvY.first, std::sqrt(desvY.second)), gauss_z(desvZ.first, std::sqrt(desvZ.second)), 
	useUnifDistrib(uniformDistribution), lifeT(lifeTime), emissionRate(emRate), limiteY(limY), color(clr), scale(partScale), partShape(shape)
{
	if (!partShape) {
		partShape = CreateShape(physx::PxSphereGeometry(scale));
	}
}

ParticleGenerator::~ParticleGenerator() {

	//quitar tambien las que ya esten muertas
	
	for (auto p : particles) {
		delete p.p;
	}
	particles.clear();
}

void ParticleGenerator::update(double dt) {
	//crear particula

	//Particle* np = new Particle(p, /*Vector3(v_ndistrib.vn_x(v.x), v_ndistrib.vn_y(v.y), v_ndistrib.vn_z(v.z))*/v, Vector3(dir.x, dir.y * -10.0, dir.z), 0.98);
	//np->changeShape(partShape);
	//particles.push_back(np);

	//for (auto p : particles) {
	//	p->integrate(dt);
	//}

	////mirar si particula esta muerta, eliminarla

	emissionAcc += dt;

	float timeBetweenEmissions = 1.0f / emissionRate;

	while (emissionAcc >= timeBetweenEmissions) {
		emitParticle();
		emissionAcc -= timeBetweenEmissions;
	}

	for (auto it = particles.begin(); it != particles.end(); ) {
		it->p->integrate(dt, Particle::SEMIEULER);

		it->currLife += dt;

		Vector3 partPos = it->p->getPosition();

		bool expired = false;
		if (it->currLife >= it->maxLife || partPos.y < -limiteY)
			expired = true;

		if (expired) {
			delete it->p;
			it = particles.erase(it);
		}
		else {
			++it;
		}
	}
}

void ParticleGenerator::emitParticle() {

	float vx, vy, vz;
	if (useUnifDistrib) {
		vx = unif_x(gen);
		vy = unif_y(gen);
		vz = unif_z(gen);
	}
	else {
		vx = gauss_x(gen);
		vy = gauss_y(gen);
		vz = gauss_z(gen);
	}
	Vector3 velocity(vx, vy, vz);

	Vector3 grav(0.0f, -10.0f, 0.0f);

	double damping = 0.98;

	Particle* part = new Particle(p, velocity, grav, damping);
	part->changeColor(color);
	//part->changeShape(partShape);
	particles.push_back({ part, 0.0f, lifeT });
}