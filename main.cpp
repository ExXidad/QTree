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
    std::vector<Point> randPoints = myRandom.getUniformRandPointVector(1000, 0, windowWidth, 0, windowHeight);
//    std::vector<Point> randPoints{Point(700, 700), Point(750, 750), Point(725, 725), Point(775, 775), Point(675, 675),
//                                  Point(625, 625)};
    graphics.drawPoints(randPoints, sf::Color::Red, true);

    QTree testTree(Rectangle(Point(windowWidth / 2, windowHeight / 2), windowWidth / 2, windowHeight / 2),3);
    testTree.addPoints(randPoints);

    graphics.drawQTree(testTree, sf::Color::White);

    Rectangle testRectangle(Point(windowWidth / 2, windowHeight / 2), 70, 75);
    graphics.drawRectangle(testRectangle, sf::Color::Green, false);

    std::vector<QTree> ovelappedTrees = testTree.findOverlappedTrees(testRectangle);


    graphics.display();
    graphics.keepWindowOpened();
    return 0;
}