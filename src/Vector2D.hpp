#pragma once

namespace Game {
struct Vector2D {
    float x = 0.f;
    float y = 0.f;
    
    Vector2D() = default;
    Vector2D(float x, float y) : x(x), y(y) {}
    
    void set(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

Vector2D operator+(const Vector2D& first, const Vector2D& second);
Vector2D& operator+=(Vector2D& first, const Vector2D& second);
Vector2D operator*(const Vector2D& vec, float scalar);
Vector2D operator*(float scalar, const Vector2D& vec);
}