//
// Created by mi on 25.06.2020.
//

#ifndef QTREE_RECTANGLE_H
#define QTREE_RECTANGLE_H

#include "Point.h"

class Rectangle {
public:
    Point origin;
    double w, h;

public:
    Rectangle();

    Rectangle(Point origin, double w, double h);

    bool contains(Point point);

    static bool rectRectIntersects(Rectangle rect1, Rectangle rect2);
};

#endif //QTREE_RECTANGLE_H
