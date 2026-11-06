#include "ForceGenerator.h"

ForceGenerator::ForceGenerator() : active(false) {

}

void ForceGenerator::updateForce(Particle* p, double dt) {

}

void ForceGenerator::activate() {
	active = !active;
}

bool ForceGenerator::isActive() const {
	return active;
}