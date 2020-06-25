//
// Created by mi on 25.06.2020.
//

#ifndef QTREE_GRAPHICS_H
#define QTREE_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Point.h"
#include "Rectangle.h"
#include "QTree.h"

typedef sf::Vector2f Vector2f;
typedef sf::Vector2i Vector2i;

class Graphics {
private:
    sf::RenderWindow *window;

public:
    Graphics(sf::RenderWindow &window);

    ~Graphics();

    void keepWindowOpened();

    void drawRectangle(Rectangle rectangle, sf::Color color = sf::Color::White, bool filled = true);

    void drawPoint(Point point, sf::Color color = sf::Color::White, bool filled = false);

    void drawQTree(QTree qTree, sf::Color color = sf::Color::White);

    void drawPoints(std::vector<Point> points, sf::Color color = sf::Color::White, bool filled = true);

    void drawRectangles(std::vector<Rectangle> rectangles, sf::Color color = sf::Color::White, bool filled = true);

    void display();
};


#endif //QTREE_GRAPHICS_H
