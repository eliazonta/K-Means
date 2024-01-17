#pragma once
#ifndef __KMEANS__
#define __KMEANS__

#include <vector>
#include <memory>
#include <iostream> // debug

#include "point.h"
#include "cluster.h"
#include "readWrite.h"

class KMeans{
private:
    int numClusters = 1, epochs;
    std::shared_ptr<std::vector<Point>> pts; // Points
    std::vector<Cluster> clusters; // clusters.size = numClusters
    std::vector<int> prova;
    void assign();
    void clearClusters();
    void computeCentroids();
    void write(std::string path);

public:
    KMeans(std::shared_ptr<std::vector<Point>> p, int _epochs, int _clusters);
    void run();
};



#endif // __KMEANS__
