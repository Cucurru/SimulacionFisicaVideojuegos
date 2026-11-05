#include "P3S_Scene.h"

#include "Vector3D.h"
#include "ParticleGenerator.h"
#include "GravityGenerator.h"
#include "WindGenerator.h"
#include "Torbellino.h"

void P3S_Scene::init() {
    ///*
    //ParticleSystem* ps1 = new ParticleSystem(500.0f);
    //pgs.push_back(ps1);

    //ParticleGenerator::ParticleConfig config1 = {
    //    2000.0f, 0.5f, //life
    //    0.0f, 1.0f, {1,0,1}, //position
    //    20.0f, 1.0f, {0,1,1}, //velocity
    //    10.0f, 1.0f, //mass
    //    {1.0f,1.0f,1.0f,1.0f} //color
    //};

    //ParticleGenerator* pg1 = new ParticleGenerator(config1);
    //ps1->addParticleGenerator(pg1);
    //ForceGenerator* fg1 = new GravityGenerator();
    //pg1->addForceGenerator(fg1);
    //ps1->addForceGenerator(fg1);
    ///*ForceGenerator* fg4 = new GravityGenerator();
    //pg1->addForceGenerator(fg4);
    //ps1->addForceGenerator(fg4);*/
    ////*/
    ///*ForceGenerator* fg2 = new GravityGenerator(Vector3(0, 15, 0));
    //pg1->addForceGenerator(fg2);
    //ps1->addForceGenerator(fg2);*/

    ParticleSystem* ps2 = new ParticleSystem(500.0f, 100.0f, 1000);
    pgs.push_back(ps2);

    ParticleGenerator::ParticleConfig config2 = {
        2000.0f, 0.5f, //life
        0.0f, 1.0f, {-5,0,1}, //position
        5.0f, 2.0f, {1,1,1}, //velocity
        1.0f, 1.5f, //mass
        {0.0f,1.0f,1.0f,1.0f} //color
    };

    ParticleGenerator* pg2 = new ParticleGenerator(config2);
    ps2->addParticleGenerator(pg2);

    explosionGen = new ExplosionGenerator(Vector3(0, 50, 0), 1000.0f, 50.0f, 1.0f, 50.0f);
    pg2->addForceGenerator(explosionGen);
    
    ///*ForceGenerator* fg2 = new GravityGenerator();
    //pg2->addForceGenerator(fg2);
    //ps2->addForceGenerator(fg2);
    //ForceGenerator* fg3 = new GravityGenerator();
    //pg2->addForceGenerator(fg3);
    //ps2->addForceGenerator(fg3);

    //Vector3 volumeMin(-10.0f, -10.0f, -10.0f);
    //Vector3 volumeMax(10.0f, 20.0f, 10.0f);
    //ForceGenerator* windGenerator = new WindGenerator(Vector3(15.0f, 0, 0), 2.0f, 0.0f, volumeMin, volumeMax);
    //pg2->addForceGenerator(windGenerator);
    ////ps2->addForceGenerator(windGenerator);

    //Vector3 volumeMin2(10.0f, -10.0f, -10.0f);
    //Vector3 volumeMax2(20.0f, 20.0f, 10.0f);
    //ForceGenerator* windGenerator2 = new WindGenerator(Vector3(15.0f, 20.0f, 0), 2.0f, 0.0f, volumeMin2, volumeMax2);
    //pg2->addForceGenerator(windGenerator2);
    //ps2->addForceGenerator(windGenerator2);*/

    Vector3 torbellinoCenter(0.0f, 0.0f, 0.0f);
    float torbellinoRadius = 150.0f;
    float k = 0.5f;
    ForceGenerator* torbellinoGen = new Torbellino(torbellinoCenter, k, torbellinoRadius, 1.0f, 0.0f);
    pg2->addForceGenerator(torbellinoGen);
    //ps2->addForceGenerator(torbellinoGen);

    ///*
    //ParticleSystem* ps3 = new ParticleSystem(500.0f, 100.0f);
    //pgs.push_back(ps3);

    //ParticleGenerator::ParticleConfig config3 = {
    //    2000.0f, 0.5f, //life
    //    0.0f, 1.0f, {1,0,1}, //position
    //    20.0f, 1.0f, {0,1,1}, //velocity
    //    20.0f, 1.0f, //mass
    //    {0.0f,0.0f,1.0f,1.0f} //color
    //};

    //ParticleGenerator* pg3 = new ParticleGenerator(config3);
    //ps3->addParticleGenerator(pg3);
    //ForceGenerator* fg4 = new GravityGenerator();
    //pg3->addForceGenerator(fg4);
    //ps3->addForceGenerator(fg4);
    //ForceGenerator* fg5 = new GravityGenerator();
    //pg3->addForceGenerator(fg5);
    //ps3->addForceGenerator(fg5);
    //*/

}

void P3S_Scene::update(double dt) {
    explosionGen->update(dt);

    for (auto pg : pgs) {
        pg->update(dt);
    }

}

void P3S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {

    if (key == 'e' || key == 'E') {
        explosionGen->trigger();
    }
}

void P3S_Scene::cleanup() {
    for (auto pg : pgs) {
        delete pg;
    }
    pgs.clear();
}