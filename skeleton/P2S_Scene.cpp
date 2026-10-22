#include "P2S_Scene.h"

#include "Vector3D.h"
#include "ParticleGenerator.h"

void P2S_Scene::init() {
    
    pgs.push_back(new ParticleGenerator(Vector3(5.0, 0.0, 0.0), Vector3(0.0f,20.0f,10.0f), 5, 100.0f, 500));

    //pgs.push_back(new ParticleGenerator(Vector3(0.0, 0.0, 0.0), { -12.0f, 12.0f }, { 35.0f, 38.0f }, { -12.0f, 12.0f }, true, 1, 80.0f, 20.0f));
    //pgs.push_back(new ParticleGenerator(Vector3(10.0, 0.0, 0.0), { 6.0f, 8.0f }, { 2.0f, 4.0f }, { -3.0f, 3.0f }, true, 20, 50.0f, 20.0f, Vector4(1.0, 0.0, 0.0, 1.0), 0.5f));
    //pgs.push_back(new ParticleGenerator(Vector3(0.0, 0.0, 10.0), { 10.0f, 10.5f }, { 10.0f, 10.5f }, { 10.0f, 10.5f }, false, 20, 80.0f, 20.0f, Vector4(0.0, 1.0, 0.0, 1.0), 0.5f));
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
}

void P2S_Scene::cleanup() {
    for (auto pg : pgs) {
        delete pg;
    }
    pgs.clear();
}