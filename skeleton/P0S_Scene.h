#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"
#include <vector>

class P0S_Scene : public Scene {
public:
    explicit P0S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& camera) override;

    void cleanup() override;

private:
    //physx::PxTransform m_transform;
    physx::PxTransform m_transform_o;
    //RenderItem* m_renderItem{ nullptr };
    RenderItem* m_renderSphere{ nullptr };
    physx::PxTransform m_transform_u;
    physx::PxTransform m_transform_v;
    physx::PxTransform m_transform_w;
    RenderItem* m_renderItem_u{ nullptr };
    RenderItem* m_renderItem_v{ nullptr };
    RenderItem* m_renderItem_w{ nullptr };
};