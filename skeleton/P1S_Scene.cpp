#include "P1S_Scene.h"
#include "Vector3D.h"

void P1S_Scene::init() {
    cam = GetCamera();

    Particle* p1 = new Particle(Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f));
    p1->changeColor(Vector4(0.0f, 0.0f, 0.0f, 1.0f));
    particles.push_back(p1);
    
    /*Particle* p2 = new Particle(Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f), Vector3(1.0f, 1.0f, 1.0f), 0.8f);
    p2->changeColor(Vector4(0.0f, 0.0f, 0.0f, 1.0f));
    particles.push_back(p2);*/
    /*
    Proyectil* pr = new Proyectil(Vector3(0.0f, 0.0f, 0.0f), 500, Vector3(10, 20, 0), Vector3D(5, 15, 0));
    Proyectil* pr2 = new Proyectil(Vector3(1.0f, 0.0f, 0.0f), 50, Vector3(10, 20, 0), Vector3D(5, 15, 0));
    pr2->changeGravity(Vector3(0.0, 2.0, 0.0));
    proyectiles.push_back(pr);
    proyectiles.push_back(pr2);*/
}

void P1S_Scene::update(double dt) {
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);

    for (auto p : particles) {
        p->integrate(dt);
    }
    for (auto pr : proyectiles) {
        pr->integrate(dt);
    }

}

void P1S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {

    if (key == 'r' || key == 'R') {
        //m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
    }
    else if (key == '+') {
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