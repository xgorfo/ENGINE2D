#pragma once
#include <vector>
#include <memory>
#include "Entity.h"
#include "Renderer.h"

class View {
    std::vector<std::shared_ptr<Entity>> entities;

public:
    void addEntity(std::shared_ptr<Entity> entity) {
        entities.push_back(entity);
    }
    void render(Renderer& renderer);
};
