#include "P2S_Scene.h"

#include "Vector3D.h"
#include "ParticleGenerator.h"

void P2S_Scene::init() {
    pgs.push_back(new ParticleGenerator(Vector3(0.0, 0.0, 0.0), { -2.0f, 2.0f }, { 5.0f, 8.0f }, { -2.0f, 2.0f }, true, 20));
    pgs.push_back(new ParticleGenerator(Vector3(10.0, 0.0, 0.0), { 6.0f, 8.0f }, { 1.0f, 2.0f }, { -1.0f, 1.0f }, true, 20, 50.0f, 20.0f, Vector4(1.0, 0.0, 0.0, 1.0), 0.5f));
    pgs.push_back(new ParticleGenerator(Vector3(0.0, 0.0, 10.0), { -3.0f, 3.5f }, { 1.0f, 6.0f }, { -2.0f, 2.5f }, false, 20, 30.0f, 300.0f, Vector4(0.0, 1.0, 0.0, 1.0), 0.5f));
}

void P2S_Scene::update(double dt) {
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);

    for (auto pg : pgs) {
        pg->update(dt);
    }

}

void P2S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {

    if (key == 'r' || key == 'R') {
        //m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
    }
    /*else if (key == '+') {
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
    }*/
}

void P2S_Scene::cleanup() {
    for (auto pg : pgs) {
        delete pg;
    }
    pgs.clear();
}