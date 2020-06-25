//
// Created by mi on 25.06.2020.
//

#include "Rectangle.h"


Rectangle::Rectangle(Point origin, double w, double h) {
    this->origin = origin;
    this->h = h;
    this->w = w;
}

bool Rectangle::contains(Point point) {
    return (origin.x - w <= point.x && point.x < origin.x + w &&
            origin.y - h <= point.y && point.y < origin.y + h);
}

Rectangle::Rectangle() {

}

bool Rectangle::rectRectIntersects(Rectangle rect1, Rectangle rect2) {
    Point p1 = rect1.origin;
    double w1 = rect1.w;
    double h1 = rect1.h;
    Point p2 = rect2.origin;
    double w2 = rect2.w;
    double h2 = rect2.h;
    return !(((p1.x - w1) >= (p2.x + w2) || (p1.x + w1 <= p2.x - w2)) ||
             ((p1.y - h1) >= (p2.y + h2) || (p1.y + h1 <= p2.y - h2)));
}
