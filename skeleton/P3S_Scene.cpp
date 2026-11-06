#include "P3S_Scene.h"

#include "Vector3D.h"

void P3S_Scene::init() {

    ParticleSystem* ps = new ParticleSystem(500.0f, 100.0f, 1000);
    pgs.push_back(ps);

    ParticleGenerator::ParticleConfig config = {
        2000.0f, 0.5f, //life
        0.0f, 1.0f, {-5,0,1}, //position
        15.0f, 1.0f, {1,0,0}, //velocity
        1.0f, 1.5f, //mass
        {1.0f,1.0f,1.0f,1.0f} //color
    };

    ParticleGenerator* pg = new ParticleGenerator(config);
    ps->addParticleGenerator(pg);

    gravGen1 = new GravityGenerator();
    pg->addForceGenerator(gravGen1);
    gravGen2 = new GravityGenerator();
    pg->addForceGenerator(gravGen2);

    Vector3 volumeMin(-10.0f, -10.0f, -10.0f);
    Vector3 volumeMax(10.0f, 20.0f, 10.0f);
    windGen = new WindGenerator(Vector3(15.0f, 0, 0), 2.0f, 0.0f, volumeMin, volumeMax);
    pg->addForceGenerator(windGen);

    Vector3 torbellinoCenter(0.0f, 0.0f, 0.0f);
    float torbellinoRadius = 150.0f;
    float k = 0.5f;
    torbellino = new Torbellino(torbellinoCenter, k, torbellinoRadius, 1.0f, 0.0f);
    pg->addForceGenerator(torbellino);

    explosionGen = new ExplosionGenerator(Vector3(0, 50, 0), 1000.0f, 50.0f, 1.0f, 50.0f);
    pg->addForceGenerator(explosionGen);

}

void P3S_Scene::update(double dt) {
    explosionGen->update(dt);

    for (auto pg : pgs) {
        pg->update(dt);
    }

}

void P3S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {

    if (key == 'e' || key == 'E') {
        explosionGen->activate();
    }
    else if (key == 'g' || key == 'G') {
        gravGen1->activate();
        gravGen2->activate();
    }
    else if (key == 'v' || key == 'V') {
        windGen->activate();
    }
    else if (key == 't' || key == 'T') {
        torbellino->activate();
    }
}

void P3S_Scene::cleanup() {
    for (auto pg : pgs) {
        delete pg;
    }
    pgs.clear();
}