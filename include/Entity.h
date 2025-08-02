#pragma once

class Renderer;

class Entity {
public:
    virtual ~Entity() = default;
    virtual void update(float dt) = 0;
    virtual void render(Renderer& renderer) = 0;
};
