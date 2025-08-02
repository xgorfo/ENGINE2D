#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window_) : window(window_) {}

void Renderer::clear() {
    window.clear(sf::Color::Black);
}

void Renderer::display() {
    window.display();
}

sf::Vector2f Renderer::worldToScreen(const Vector2D& point) const {
    // Простое преобразование: масштаб 1:1, без сдвига
    return sf::Vector2f(point.x, point.y);
}

void Renderer::drawPolygonWorld(const std::vector<Vector2D>& points, sf::Color color) {
    if(points.empty()) return;

    sf::ConvexShape polygon;
    polygon.setPointCount(points.size());

    for(size_t i = 0; i < points.size(); ++i) {
        sf::Vector2f screenPoint = worldToScreen(points[i]);
        polygon.setPoint(i, screenPoint);
    }

    polygon.setFillColor(color);
    window.draw(polygon);
}
