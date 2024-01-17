#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include <math.h>
#include <vector>
#include <iostream>

class Point{
private:
    int pointID, clusterID, dimensions;
    double distance; // distance from centroid
    std::vector<double> features; // point features [features.size = dimensions]
    
public:
    Point();
    Point(int pid);
    Point(int pid, std::vector<double> f);
    Point(const Point& p);

    int getID(){return pointID;}
    int getCluster(){return clusterID;}
    double getDist(){return distance;}
    double getDimensions(){return dimensions;}
    std::vector<double> getFeatures(){return features;}

    void setID(int pid){pointID = pid;}
    void setCluster(int cid){clusterID = cid;}
    void setDist(double dist){distance = dist;}

    double dist(Point p);
    friend std::ostream& operator<<(std::ostream &os, const Point p);
};

#endif // __POINT_H__
