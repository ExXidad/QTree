//
// Created by mi on 25.06.2020.
//

#ifndef QTREE_QTREE_H
#define QTREE_QTREE_H

#include "vector"
#include "Point.h"
#include "Rectangle.h"
#include <queue>

class QTree {
private:
    int capacity;
    Rectangle boundary;

    std::vector<Point> points;
    std::vector<QTree> subTrees;
    bool divided = false;

public:
    const std::vector<QTree> &getSubTrees() const;

    const Rectangle &getBoundary() const;

    std::vector<QTree> findOverlappedTrees(Rectangle Rectangle);

private:
    void divide();

    void addPointToDivision(Point point);



public:
    QTree();

    QTree(Rectangle boundary, int capacity);

    bool contains(Point point);

    void addPoint(Point point);

    void addPoints(std::vector<Point> points);

    std::vector<Point> getPointsInRectangle(Rectangle rectangle);
};


#endif //QTREE_QTREE_H
