//
// Created by mi on 25.06.2020.
//

#include "QTree.h"

QTree::QTree(Rectangle boundary, int capacity) {
    this->boundary = boundary;
    this->capacity = capacity;
}

void QTree::addPoint(Point point) {
    if (points.size() < capacity) points.emplace_back(point);
    else {
        if (!divided) {
            divide();
            for (auto &iterPoint : points) addPointToDivision(iterPoint);
        }

        addPointToDivision(point);
    }
}

void QTree::divide() {
    subTrees.resize(4);

    double x = boundary.origin.x;
    double y = boundary.origin.y;
    double w = boundary.w;
    double h = boundary.h;

    subTrees[0] = QTree(
            Rectangle(Point(x + w / 2, y + h / 2), w / 2, h / 2), capacity);
    subTrees[1] = QTree(
            Rectangle(Point(x + w / 2, y - h / 2), w / 2, h / 2), capacity);
    subTrees[2] = QTree(
            Rectangle(Point(x - w / 2, y - h / 2), w / 2, h / 2), capacity);
    subTrees[3] = QTree(
            Rectangle(Point(x - w / 2, y + h / 2), w / 2, h / 2), capacity);

    divided = true;
}

void QTree::addPointToDivision(Point point) {
    for (auto &tree : subTrees) {
        if (tree.contains(point)) {
            tree.addPoint(point);
            break;
        }
    }
}

QTree::QTree() {

}

bool QTree::contains(Point point) {
    return boundary.contains(point);
}

const std::vector<QTree> &QTree::getSubTrees() const {
    return subTrees;
}

const Rectangle &QTree::getBoundary() const {
    return boundary;
}

void QTree::addPoints(std::vector<Point> newPoints) {
    for (auto &point : newPoints) {
        addPoint(point);
    }
}

std::vector<Point> QTree::getPointsInRectangle(Rectangle rectangle) {
    std::vector<Point> overlappedPoints;
    std::vector<Rectangle> overlappedRectangles;


}

std::vector<QTree> QTree::findOverlappedTrees(Rectangle Rectangle) {
    std::vector<QTree> result;
    std::queue<QTree> subTreesQueue;
    subTreesQueue.emplace(*this);

    while (!subTreesQueue.empty())
        if (subTreesQueue.front().subTrees.empty())
            result.emplace_back(subTreesQueue.front().subTrees.empty());
        else {
            subTreesQueue.emplace(subTreesQueue.front().subTrees);
            subTreesQueue.pop();
        }

    return result;
}



