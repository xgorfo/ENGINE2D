#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Vector2D.h"

class Renderer {
public:
    Renderer(sf::RenderWindow& window_);
    void clear();
    void display();
    sf::Vector2f worldToScreen(const Vector2D& point) const;
    void drawPolygonWorld(const std::vector<Vector2D>& points, sf::Color color);

private:
    sf::RenderWindow& window;
};
