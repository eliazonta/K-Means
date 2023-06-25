#ifndef __POINT_H__
#define __POINT_H__

class Point{
private:
    double x, y, z;
    int k;
    double minDist;
public:
    Point();
    Point(double x, double y, double z);

    double getX();
    double getY();
    double getZ();
    int getK();
    double getMinDist();

    void setX(int _x);
    void setY(int _y);
    void setZ(int _z);
    void setK(int _k);
    void setMinDist(double md);
    
    double dist(Point p);
};

#endif