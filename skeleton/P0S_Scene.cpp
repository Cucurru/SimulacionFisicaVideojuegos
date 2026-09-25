#include "P0S_Scene.h"
#include "Vector3D.h"

void P0S_Scene::init() {
    //// Ejemplo: Creación de una esfera usando las utilidades de render existentes
    //physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(2.0f));
    //m_transform = physx::PxTransform(physx::PxVec3(0.0f, 10.0f, 0.0f));

    //// Se registra el RenderItem exactamente como en la plantilla original
    //m_renderItem = new RenderItem(shape, &m_transform, Vector4(1.0f, 0.0f, 0.0f, 1.0f));

    physx::PxShape* sphere = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transform_o = physx::PxTransform(physx::PxVec3(0.0f, 0.0f, 0.0f));

    m_renderSphere = new RenderItem(sphere, &m_transform_o, Vector4(1.0f, 1.0f, 1.0f, 1.0f));

    Vector3D u(3.0f, 1.0f, 0.0f);
    Vector3D v(0.0f, 4.0f, 0.0f);
    Vector3D w = u.cross(v);
    u.normalize();
    v.normalize();
    w.normalize();
    u = u * 5.0f;
    v = v * 5.0f;
    w = w * 5.0f;
    physx::PxShape* uShape = CreateShape(physx::PxSphereGeometry(1.0f));
    m_transform_u = physx::PxTransform(u);
    m_renderItem_u = new RenderItem(uShape, &m_transform_u, Vector4(1.0f, 0.0f, 0.0f, 1.0f));
    physx::PxShape* vShape = CreateShape(physx::PxSphereGeometry(1.0f));
    m_transform_v = physx::PxTransform(v);
    m_renderItem_v = new RenderItem(vShape, &m_transform_v, Vector4(0.0f, 1.0f, 0.0f, 1.0f));
    physx::PxShape* wShape = CreateShape(physx::PxSphereGeometry(1.0f));
    m_transform_w = physx::PxTransform(w);
    m_renderItem_w = new RenderItem(wShape, &m_transform_w, Vector4(0.0f, 0.0f, 1.0f, 1.0f));




}

void P0S_Scene::update(double dt) {
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);

}

void P0S_Scene::keyPress(unsigned char key, const physx::PxTransform& camera) {
    if (key == 'r' || key == 'R') {
        //m_transform.p = physx::PxVec3(0.0f, 10.0f, 0.0f); // Reset
    }
}

void P0S_Scene::cleanup() {
    //if (m_renderItem) {
    //    m_renderItem->release(); // Deregistra y destruye el item
    //    m_renderItem = nullptr;
    //}

    if (m_renderSphere) {
        m_renderSphere->release();
        m_renderSphere = nullptr;
    }

    if (m_renderItem_u) {
        m_renderItem_u->release(); // Deregistra y destruye el item
        m_renderItem_u = nullptr;
    }

    if (m_renderItem_v) {
        m_renderItem_v->release(); // Deregistra y destruye el item
        m_renderItem_v = nullptr;
    }

    if (m_renderItem_w) {
        m_renderItem_w->release(); // Deregistra y destruye el item
        m_renderItem_w = nullptr;
    }
}