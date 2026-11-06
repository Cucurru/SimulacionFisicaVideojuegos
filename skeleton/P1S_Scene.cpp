#include "P1S_Scene.h"
#include "Vector3D.h"

void P1S_Scene::init() {
    cam = GetCamera();

}

void P1S_Scene::update(double dt) {

    for (auto p : particles) {
        p->integrate(dt);
    }
    for (auto pr : proyectiles) {
        pr->integrate(dt);
    }

}

void P1S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {

    if (key == '+') {
        for (Proyectil* p : proyectiles) {
            auto vels = p->getVelocities();
            p->changeVel(vels.first + Vector3(0.0, 0.0, 5.0), vels.second + Vector3(0.0, 0.0, 2.0));
        }
    }
    else if (key == '-') {
        for (Proyectil* p : proyectiles) {
            auto vels = p->getVelocities();
            p->changeVel(vels.first - Vector3(0.0, 0.0, 5.0), vels.second - Vector3(0.0, 0.0, 2.0));
        }
    }
    else if (key == 'z') {
        Vector3 camDir = cam->getDir();
        Proyectil* np = new Proyectil(cam->getTransform().p, 500, camDir * 20.0, camDir * 10.0);
        proyectiles.push_back(np);
    }
    else if (key == 'x') {
        Vector3 camDir = cam->getDir();
        Proyectil* np = new Proyectil(cam->getTransform().p, 500, camDir * 40.0, camDir * 30.0);
        proyectiles.push_back(np);
    }
    else if (key == 'c') {
        Vector3 camDir = cam->getDir();
        Proyectil* np = new Proyectil(cam->getTransform().p, 500, camDir * 70.0, camDir * 30.0);
        proyectiles.push_back(np);
    }
    else if (key == 'v') {
        Vector3 camDir = cam->getDir();
        Proyectil* np = new Proyectil(cam->getTransform().p, 500, camDir * 20.0, camDir * 10.0, Vector3(0.0, 5.0, 0.0));
        proyectiles.push_back(np);
    }
}

void P1S_Scene::cleanup() {
    for (auto p : particles) {
        delete p;
    }
    particles.clear();
    for (auto p : proyectiles) {
        delete p;
    }
    proyectiles.clear();
}