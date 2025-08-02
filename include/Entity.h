#pragma once
#include "Vector2D.h"
#include "Renderer.h"

class Renderer;

class Entity {
public:
    virtual ~Entity() = default;
    virtual void update(float dt) = 0;
    virtual void render(Renderer& renderer) = 0;
    void setPosition(const Vector2D& pos) { position = pos; }
    Vector2D getPosition() const { return position; }
protected:
    Vector2D position;
};
