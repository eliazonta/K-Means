#pragma once
#ifndef __CLUSTER__
#define __CLUSTER__

#include <vector>
#include "point.h"
// #include "readWrite.h"
#include <iostream> // debug
#include <memory>

static int cid = 0;

class Cluster
{
private:
    int clusterID;
    Point centroid;
    std::vector<double> cumulative;    // cumulative feature [length = numFeatures]
    std::shared_ptr<std::vector<Point>> pts; // Points
public:
    Cluster();
    Cluster(std::shared_ptr<std::vector<Point>> p);
    Cluster(const Cluster& c);
    void assign(Point* p);
    void computeCentroid();
    void clear(){pts->clear();}
    Point getCentroid(){return centroid;}
};


#endif // __CLUSTER__