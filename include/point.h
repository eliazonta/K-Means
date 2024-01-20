#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>
#include <vector>
#include <iostream>

class Point
{
private:
    double x, y;
    // std::vector<double> features; // point features [features.size = dimensions]
    
public:
    Point();
    Point(double x, double y);
    // Point(std::vector<double> &f);
    Point(const Point& p);

    double X() const {return x;}
    double Y() const {return y;}

    void X(double nx) { x = nx; }
    void Y(double ny) { y = ny; }

    static double distance(const Point &p1, const Point &p2);
};

class Observation : public Point
{
    int clusterID;

public:
    Observation(double, double, int);
    Observation() : Point(), clusterID(-1){};

    void setClusterID(int id) { clusterID = id; }

    int getClusterID() const { return clusterID; }
    Point getPoint() const { return Point(X(), Y()); }
    
    friend std::ostream &operator<<(std::ostream &os, const Observation &observation);
};

using ObservationsWithIterations = std::pair<std::vector<Observation>, int>;

#endif // __POINT_H__
