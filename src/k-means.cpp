/*
    K-Means algorithm

    - random centroids init

    for e in EPOCHS
        assign points to clusters 
        compute centrods for each cluster
        update centroids 
*/

#include "../include/k-means.h"
// #include <omp.h>
// #define DEBUG

double KMeans::costFunction(const std::vector<Observation> &points, const std::vector<Observation> &centroids)
{
    double totdist = 0;
// #pragma omp parallel for reduction(+ : totdist)
    for (const auto &p : points)
        for (const auto &c : centroids)
            totdist += Point::distance(p, c);
    return totdist;
}

void KMeans::assignCluster(Observation &point, const std::vector<Observation> &centroids)
{
    double dist = std::numeric_limits<double>::max();
    for (const auto &centroid : centroids)
    {
        const auto newDist = Point::distance(point.getPoint(), centroid.getPoint());
        if (newDist < dist)
        {
            point.setClusterID(centroid.getClusterID());
            dist = newDist;
        }
    }
}

void KMeans::updateCentroids(const std::vector<Observation> &initPoints, std::vector<Observation> &centroids)
{
#pragma omp parallel for
    for (auto &centroid : centroids)
    {
        double x = 0, y = 0;
        int counter = 0;
#pragma omp parallel for default(shared) reduction(+ : x, y, counter)
        for (const auto &p : initPoints)
        {
            if (p.getClusterID() == centroid.getClusterID())
            {
                x += p.X();
                y += p.Y();
                ++counter;
            }
        }
        if (counter > 0)
        {
            x /= counter;
            y /= counter;
            centroid.X(x);
            centroid.Y(y);
        }
    }
}

ObservationsWithIterations KMeans::fit(std::vector<Observation> &initPoints, unsigned int k, double tolerance, int maxIteration)
{   
    srand(time(NULL));
    std::vector<Observation> centroids;
    std::vector<int> positions(initPoints.size());
    std::iota(positions.begin(), positions.end(), 0);
    std::shuffle(positions.begin(), positions.end(), [](int i) { return rand() % i; });

    
    for (unsigned int i = 0; i < k; ++i)
    {
        const auto point = initPoints.at(positions.at(i)).getPoint();
        centroids.emplace_back(Observation(point.X(), point.Y(), i));
    }

    for (int i = 0; i < maxIteration; ++i)
    {
        double costOld = costFunction(initPoints, centroids);
// #pragma omp parallel for
        for (auto &point : initPoints)
            assignCluster(point, centroids);

        updateCentroids(initPoints, centroids);

        double costNew = costFunction(initPoints, centroids);
        if (std::abs(costOld - costNew) < tolerance)
        {
            // std::cout << "EPOCH: " << i << "/ " << maxIteration <<  '\n';
            return std::make_pair(centroids, i);
        }
    }
    return std::make_pair(centroids, maxIteration);
}



