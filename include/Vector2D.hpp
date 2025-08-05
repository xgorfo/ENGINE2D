
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

class Vector2D {
public:
    Vector2D(float x = 0.0f, float y = 0.0f);
    float getX() const;
    float getY() const;
    void set(float x, float y);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator*(float scalar) const;

private:
    float x, y;
};

#endif
