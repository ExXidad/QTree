//
// Created by mi on 25.06.2020.
//

#include "Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

std::ostream &operator<<(std::ostream &stream, Point &point) {
    std::cout << "X: " << point.x << " Y: " << point.y << std::endl;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, std::vector<Point> points) {
    std::cout << "-------------------" << std::endl;
    for (auto &point : points) {
        std::cout << "X: " << point.x << " Y: " << point.y << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    return stream;
}

Point::Point() {

}
