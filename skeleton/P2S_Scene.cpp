#include "P2S_Scene.h"

#include "Vector3D.h"
#include "ParticleGenerator.h"
#include "GravityGenerator.h"

void P2S_Scene::init() {
    
    ParticleSystem* ps1 = new ParticleSystem(500.0f);
    pgs.push_back(ps1);

    ParticleGenerator::ParticleConfig config1 = { 
        2000.0f, 0.5f, //life
        0.0f, 1.0f, {1,0,1}, //position
        20.0f, 1.0f, {0,1,1}, //velocity
        10.0f, 1.0f, //mass
        {1.0f,1.0f,1.0f,1.0f} //color
    };

    ParticleGenerator* pg1 = new ParticleGenerator(config1);
    ps1->addParticleGenerator(pg1);
    ForceGenerator* fg1 = new GravityGenerator();
    pg1->addForceGenerator(fg1);
    ps1->addForceGenerator(fg1);

    /*ForceGenerator* fg2 = new GravityGenerator(Vector3(0, 15, 0));
    pg1->addForceGenerator(fg2);
    ps1->addForceGenerator(fg2);*/
}

void P2S_Scene::update(double dt) {

    for (auto pg : pgs) {
        pg->update(dt);
    }

}

void P2S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {

    if (key == 'r' || key == 'R') {

    }
}

void P2S_Scene::cleanup() {
    for (auto pg : pgs) {
        delete pg;
    }
    pgs.clear();
}