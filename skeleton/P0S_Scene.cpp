#include "P0S_Scene.h"

void P0S_Scene::init() {
    // Ejemplo: Creación de una esfera usando las utilidades de render existentes
    physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transform = physx::PxTransform(physx::PxVec3(0.0f, 10.0f, 0.0f));

    // Se registra el RenderItem exactamente como en la plantilla original
    m_renderItem = new RenderItem(shape, &m_transform, Vector4(1.0f, 0.0f, 0.0f, 1.0f));

    physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transform2 = physx::PxTransform(physx::PxVec3(0.0f, 0.0f, 0.0f));

    m_renderSphere = new RenderItem(sphere, &m_transform2, Vector4(0.0f, 1.0f, 0.0f, 1.0f));
}

void P0S_Scene::update(double dt) {
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);
}

void P0S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {
    if (key == 'r' || key == 'R') {
        m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
    }
}

void P0S_Scene::cleanup() {
    if (m_renderItem) {
        m_renderItem->release(); // Deregistra y destruye el item
        m_renderItem = nullptr;
    }

    if (m_renderSphere) {
        m_renderSphere->release();
        m_renderSphere = nullptr;
    }
}