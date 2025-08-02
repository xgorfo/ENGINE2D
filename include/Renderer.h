#pragma once
#include <SFML/Graphics.hpp>
#include "Basis.h"
#include "Vector2D.h"
#include <vector>

class Renderer {
public:
    Renderer(sf::RenderWindow& window, const Basis& basis);
    void clear();
    void display();
    void drawPolygonWorld(const std::vector<Vector2D>& points, sf::Color color);
    const Basis& getBasis() const;
    sf::RenderWindow& getWindow();
private:
    sf::RenderWindow& window;
    Basis basis;
    sf::Vector2f worldToScreen(const Vector2D& point) const;
};