
#ifndef CALC_H
#define CALC_H

#endif //CALC_H
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

std::string InputToLine();

std::vector<std::string> LineToEquation(const std::string &);
//
double add(double x, double y);
//
double subtract(double x, double y);
// произведение
double multiply(double x, double y);
// частное
double division(double x, double y);
// перевод числа из положительного в отрицательное
double minus(double x);
// синус
double sinus(double x);
// косинус
double cosine(double x);
// тангенс
double tangent(double x);
// котангенс
double cotangent(double x);
// экспонента
double exponent(double x);

std::vector<std::string> NormalToPolish(const std::vector<std::string>&);

double PolishCalc(const std::vector<std::string>&);
