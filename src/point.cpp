#include <iostream>
#include "../include/point.h"

Point::Point():
    x(0), y(0), z(0), k(-1), minDist(__DBL_MAX__){}

Point::Point(double x, double y, double z):
    x(x), y(y),z(z), k(-1), minDist(__DBL_MAX__){}

double Point::X(){return x;}
double Point::Y(){return y;}
double Point::Z(){return z;}
int Point::K(){return k;}
double Point::getMinDist(){return minDist;}

void Point::X(int _x){x = _x;}
void Point::Y(int _y){y = _y;}
void Point::Z(int _z){z = _z;}
void Point::K(int _k){k = _k;}
void Point::setMinDist(double md){minDist = md;}

double Point::dist(Point p){
    return sqrt(pow(p.X() - x, 2) + pow(p.X() - y, 2) + pow(p.X() - z, 2));
}
