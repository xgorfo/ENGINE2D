#include "Renderer.h"
#include "Vector2D.h"
#include "Basis.h"
#include <SFML/Graphics.hpp>
#include <vector>


Renderer::Renderer(sf::RenderWindow& window_, const Basis& basis_) : window(window_), basis(basis_) {}

void Renderer::clear() { window.clear(sf::Color::Black); }
void Renderer::display() { window.display(); }

sf::RenderWindow& Renderer::getWindow() { return window; }
const Basis& Renderer::getBasis() const { return basis; }

sf::Vector2f Renderer::worldToScreen(const Vector2D& point) const {
    Vector2D local = basis.fromStandardCoords(point);
    return sf::Vector2f(local.x, local.y);
}

void Renderer::drawPolygonWorld(const std::vector<Vector2D>& points, sf::Color color) {
    sf::ConvexShape shape;
    shape.setPointCount(points.size());
    for (size_t i = 0; i < points.size(); ++i) {
        shape.setPoint(i, worldToScreen(points[i]));
    }
    shape.setFillColor(color);
    window.draw(shape);
}