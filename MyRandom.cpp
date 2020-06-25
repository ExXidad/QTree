//
// Created by mi on 25.06.2020.
//

#include "MyRandom.h"

MyRandom::MyRandom() {
    this->gen = std::mt19937(time(nullptr));
}

int MyRandom::getUniformRandInt(double left, double right) {
    std::uniform_int_distribution<> num(left, right);
    return num(gen);
}

double MyRandom::getUniformRandReal(double left, double right) {
    std::uniform_real_distribution<> num(left, right);
    return num(gen);
}

std::vector<double> MyRandom::getUniformRandRealVector(int n, double left, double right) {
    std::uniform_real_distribution<> num(left, right);
    std::vector<double> result(n);
    for (int i = 0; i < n; ++i) result[i] = num(gen);
    return result;
}

std::vector<std::vector<double>>
MyRandom::getUniformRandRealPairVector(int n, double left, double right, double bottom, double top) {
    std::uniform_real_distribution<> x(left, right);
    std::uniform_real_distribution<> y(bottom, top);
    std::vector<std::vector<double>> result(n);
    for (int i = 0; i < n; ++i) result[i] = {x(gen), y(gen)};
    return result;
}

std::vector<Point> MyRandom::getUniformRandPointVector(int n, double left, double right, double bottom, double top) {
    std::uniform_real_distribution<> x(left, right);
    std::uniform_real_distribution<> y(bottom, top);
    std::vector<Point> result(n);
    for (int i = 0; i < n; ++i) result[i] = {x(gen), y(gen)};
    return result;
}
