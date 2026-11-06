#pragma once

#include "Scene.h"
#include "RenderUtils.hpp"
#include <vector>
#include "ParticleSystem.h"
#include "ForceGenerator.h"
#include "ParticleGenerator.h"
#include "GravityGenerator.h"
#include "WindGenerator.h"
#include "Torbellino.h"
#include "ExplosionGenerator.h"

class P3S_Scene : public Scene {
public:
    explicit P3S_Scene(std::string name) : Scene(std::move(name)) {}

    void init() override;

    void update(double dt) override;

    void keyPress(unsigned char key, const physx::PxTransform& camera) override;

    void cleanup() override;

private:
    std::vector<ParticleSystem*> pgs;

    GravityGenerator* gravGen1;
    GravityGenerator* gravGen2;

    WindGenerator* windGen;

    Torbellino* torbellino;

    ExplosionGenerator* explosionGen;
};