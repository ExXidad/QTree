//
// Created by mi on 25.06.2020.
//

#ifndef QTREE_MYRANDOM_H
#define QTREE_MYRANDOM_H

#include <random>
#include <ctime>
#include <vector>
#include "Point.h"

class MyRandom {
private:
    std::mt19937 gen;

public:
    MyRandom();

    int getUniformRandInt(double left, double right);

    double getUniformRandReal(double left, double right);

    std::vector<double> getUniformRandRealVector(int n, double left = 0, double right = 1);

    std::vector<std::vector<double>>
    getUniformRandRealPairVector(int n, double left = 0, double right = 1, double bottom = 0, double top = 1);

    std::vector<Point>
    getUniformRandPointVector(int n, double left = 0, double right = 1, double bottom = 0, double top = 1);
};


#endif //QTREE_MYRANDOM_H
