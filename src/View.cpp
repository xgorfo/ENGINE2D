#include "View.h"
#include "Renderer.h" 

void View::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void View::update(float dt) {
    for (auto& e : entities) e->update(dt);
}

void View::render(Renderer& renderer) {
    for (auto& e : entities) e->render(renderer);
}