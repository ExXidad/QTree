#include <iostream>
#include <vector>

#include "Rectangle.h"
#include "Point.h"
#include "QTree.h"
#include "MyRandom.h"
#include "myTypes.h"
#include "Graphics.h"

#include <SFML/Graphics.hpp>

int main() {
    double windowWidth = 800;
    double windowHeight = 800;

    sf::ContextSettings settings;
    settings.majorVersion = 3.1;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "QuadTree",
                            sf::Style::Default, settings);

    window.clear(sf::Color::Black);

    Graphics graphics(window);

    MyRandom myRandom;
    std::vector<Point> randPoints = myRandom.getUniformRandPointVector(500, 0, windowWidth, 0, windowHeight);
    graphics.drawPoints(randPoints, sf::Color::Red, true);

    QTree testTree(Rectangle(Point(windowWidth / 2, windowHeight / 2), windowWidth / 2, windowHeight / 2),10);
    testTree.addPoints(randPoints);

    graphics.drawQTree(testTree, sf::Color::White);

    Rectangle testRectangle(Point(windowWidth / 2, windowHeight / 2), 70, 75);
    graphics.drawRectangle(testRectangle, sf::Color::Green, false);

    std::vector<QTree> ovelappedTrees = testTree.findOverlappedTrees(testRectangle);
    for (auto &ovelappedTree : ovelappedTrees) {
        graphics.drawQTree(ovelappedTree, sf::Color::Red);
    }

    std::vector<Point> overlappedPoints = testTree.findOverlappedPoints(testRectangle);
    graphics.drawPoints(overlappedPoints, sf::Color::Green);

    graphics.display();
    graphics.keepWindowOpened();
    return 0;
}