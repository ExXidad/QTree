//
// Created by mi on 25.06.2020.
//

#include "Graphics.h"

Graphics::Graphics(sf::RenderWindow &window) {
    this->window = &window;
}


Graphics::~Graphics() {
    delete (window);
}

void Graphics::keepWindowOpened() {
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event))
            if (event.type == sf::Event::Closed) {
                window->close();
                break;
            }
    }
}

void Graphics::drawPoint(Point point, sf::Color color, bool filled) {
    sf::CircleShape pointShape;
    int dotRadius = 2;
    pointShape.setPosition(Vector2f(point.x, point.y) - Vector2f(dotRadius, dotRadius));
    pointShape.setFillColor(color);
    if (filled) pointShape.setFillColor(color); else pointShape.setFillColor(sf::Color::Transparent);
    pointShape.setOutlineColor(color);
    pointShape.setOutlineThickness(1);
    pointShape.setRadius(dotRadius);
    window->draw(pointShape);
}

void Graphics::drawRectangle(Rectangle rectangle, sf::Color color, bool filled) {
    sf::RectangleShape rectangleShape;
    double x = rectangle.origin.x;
    double y = rectangle.origin.y;
    double w = rectangle.w;
    double h = rectangle.h;
    rectangleShape.setPosition(Vector2f(x, y) - Vector2f(w, h));
    rectangleShape.setSize(Vector2f(2 * w, 2 * h));
    if (filled) rectangleShape.setFillColor(color); else rectangleShape.setFillColor(sf::Color::Transparent);
    rectangleShape.setOutlineColor(color);
    rectangleShape.setOutlineThickness(1);
    window->draw(rectangleShape);
}

void Graphics::drawQTree(QTree qTree, sf::Color color) {
    drawRectangle(qTree.getBoundary(), color, false);
    for (auto &subTree : qTree.getSubTrees()) {
        drawQTree(subTree, color);
    }
}

void Graphics::drawPoints(std::vector<Point> points, sf::Color color, bool filled) {
    for (auto &point : points) {
        drawPoint(point, color, filled);
    }
}

void Graphics::display() {
    window->display();
}

void Graphics::drawRectangles(std::vector<Rectangle> rectangles, sf::Color color, bool filled) {
    for (auto &rectangle : rectangles) {

    }
}

