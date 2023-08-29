#include <iostream>
#include "../include/point.h"

Point::Point():
    x(0), y(0), z(0), k(-1), minDist(__DBL_MAX__){}

Point::Point(double x, double y, double z):
    x(x), y(y),z(z), k(-1), minDist(__DBL_MAX__){}

double Point::getX(){return x;}
double Point::getY(){return y;}
double Point::getZ(){return z;}
int Point::getK(){return k;}
double Point::getMinDist(){return minDist;}

void Point::setX(int _x){x = _x;}
void Point::setY(int _y){y = _y;}
void Point::setZ(int _z){z = _z;}
void Point::setK(int _k){k = _k;}
void Point::setMinDist(double md){minDist = md;}

double Point::dist(Point p){
    return sqrt(pow(p.getX() - x, 2) + pow(p.getY() - y, 2) + pow(p.getZ() - z, 2));
}
