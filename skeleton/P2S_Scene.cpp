#include "P2S_Scene.h"

#include "Vector3D.h"
#include "ParticleGenerator.h"
#include "GravityGenerator.h"

void P2S_Scene::init() {
    ///*
    ParticleSystem* ps1 = new ParticleSystem(150.0f);
    pgs.push_back(ps1);

    ParticleGenerator::ParticleConfig config1 = { 
        500.0f, 0.5f, //life
        0.0f, 1.0f, {1,0,1}, //position
        40.0f, 5.0f, {0,1,0}, //velocity
        10.0f, 1.0f, //mass
        {1.0f,1.0f,1.0f,1.0f} //color
    };

    ParticleGenerator* pg1 = new ParticleGenerator(config1);
    ps1->addParticleGenerator(pg1);
    ForceGenerator* fg1 = new GravityGenerator();
    fg1->activate();
    pg1->addForceGenerator(fg1);

    ParticleSystem* ps2 = new ParticleSystem(-100.0f, 100.0f);
    pgs.push_back(ps2);

    ParticleGenerator::ParticleConfig config2 = {
        1000.0f, 0.5f, //life
        0.0f, 1.0f, {30,0,0}, //position
        30.0f, 0.5f, {1,1,0}, //velocity
        20.0f, 1.0f, //mass
        {1.0f,0.0f,0.0f,1.0f} //color
    };

    ParticleGenerator* pg2 = new ParticleGenerator(config2);
    ps2->addParticleGenerator(pg2);
    ForceGenerator* fg2 = new GravityGenerator();
    fg2->activate();
    pg2->addForceGenerator(fg2);
    ForceGenerator* fg3 = new GravityGenerator();
    fg3->activate();
    pg2->addForceGenerator(fg3);

    //
    ParticleSystem* ps3 = new ParticleSystem(-100.0f, 100.0f);
    pgs.push_back(ps3);

    ParticleGenerator::ParticleConfig config3 = {
        1000.0f, 0.5f, //life
        0.0f, 1.0f, {-50,0,0}, //position
        5.0f, 10.0f, {0,1,0}, //velocity
        20.0f, 1.0f, //mass
        {0.0f,1.0f,0.0f,1.0f} //color
    };

    ParticleGenerator* pg3 = new ParticleGenerator(config3);
    ps3->addParticleGenerator(pg3);
    ForceGenerator* fg4 = new GravityGenerator();
    fg4->activate();
    pg3->addForceGenerator(fg4);
    ForceGenerator* fg5 = new GravityGenerator();
    fg5->activate();
    pg3->addForceGenerator(fg5);
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