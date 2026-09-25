#include "P1S_Scene.h"
#include "Vector3D.h"

void P1S_Scene::init() {

    Particle* p1 = new Particle(Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f));
    particles.push_back(p1);

    Particle* p2 = new Particle(Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 0.0f, 0.0f), Vector3(2.0f, 2.0f, 2.0f));
    p2->changeColor(Vector4(0.0f, 0.0f, 0.0f, 1.0f));
    particles.push_back(p2);
}

void P1S_Scene::update(double dt) {
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);

    for (auto p : particles) {
        p->integrate(dt);
        Vector3 a = p->getAccel();
        p->changeAccel(Vector3(1.0f, a.y*0.5f, 1.f));
    }

}

void P1S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {
    if (key == 'r' || key == 'R') {
        //m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
    }
}

void P1S_Scene::cleanup() {
    for (auto p : particles) {
        delete p;
    }
    particles.clear();
}