#pragma once
#include <vector>
#include <memory>
#include "Entity.h"

class Renderer;

class View {
public:
    void addEntity(std::shared_ptr<Entity> entity);
    void update(float dt);
    void render(Renderer& renderer);
private:
    std::vector<std::shared_ptr<Entity>> entities;
};