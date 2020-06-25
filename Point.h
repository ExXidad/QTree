//
// Created by mi on 25.06.2020.
//

#ifndef QTREE_POINT_H
#define QTREE_POINT_H


#include <iostream>
#include <vector>

class Point {
public:
    double x, y;

public:
    Point();
    Point(double x, double y);
};

std::ostream &operator<<(std::ostream &stream, Point &point);
std::ostream &operator<<(std::ostream &stream, std::vector<Point> points);

#endif //QTREE_POINT_H
