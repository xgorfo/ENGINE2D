#pragma once

namespace Game {
struct Vector2D {
    float x = 0.f;
    float y = 0.f;
};

Vector2D operator+(Vector2D first, Vector2D second);
Vector2D& operator+=(Vector2D& first, Vector2D second);
Vector2D operator*(Vector2D vec, float scalar);
Vector2D operator*(float scalar, Vector2D vec);
Vector2D& operator*=(Vector2D& vec, float scalar);
}

