#pragma once
#ifndef __KMEANS__
#define __KMEANS__

#include <vector>
#include <memory>
#include <iostream> // debug
#include <limits>
#include <tuple>
#include <algorithm>

#include "point.h"
#include "utils.h"

class KMeans
{
private:
    static double costFunction(const std::vector<Observation> &points, const std::vector<Observation> &centroids);
    static void assignCluster(Observation &point, const std::vector<Observation> &centroids);
    static void updateCentroids(const std::vector<Observation> &initPoints, std::vector<Observation> &centroids);
    
    // void write(std::string path);
public:
    static ObservationsWithIterations fit(std::vector<Observation> &initPoints, unsigned int k, double tolerance = .0001, int maxIteration = 500);
};



#endif // __KMEANS__
