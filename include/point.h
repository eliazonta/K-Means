#ifndef __POINT_H__
#define __POINT_H__
#include <math.h>

class Point{
private:
    double x, y, z;
    int k;
    double minDist;
public:
    Point();
    Point(double x, double y, double z);

    double X();
    double Y();
    double Z();
    int K();
    double getMinDist();

    void X(int _x);
    void Y(int _y);
    void Z(int _z);
    void K(int _k);
    void setMinDist(double md);
    
    double dist(Point p);
};

#endif
