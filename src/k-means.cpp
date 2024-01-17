/*
    K-Means algorithm

    - random centroids init

    for e in EPOCHS
        - assign points to clusters 
        compute centrods for each cluster
        update centroids 
*/

#include "../include/k-means.h"
#include <omp.h>
// #define DEBUG


KMeans::KMeans(std::shared_ptr<std::vector<Point>> p, int _epochs, int _clusters):
    pts(p), epochs(_epochs), numClusters(_clusters)
{
    std::cout << "Constructor called" << std::endl;

    for(size_t i = 0; i < numClusters; ++i)
    {
        clusters.push_back(Cluster()); 
    }
    // clusters.reserve(numClusters);

    if (!pts || pts->empty()) 
    {
        std::cerr << "Error: Null or empty vector passed to constructor." << std::endl;
        return;
    }

    std::srand(time(nullptr));
    // clusters.resize(numClusters, Cluster()); // segfault
    
    // for(size_t i = 0; i < numClusters; ++i)
    // {
    //     clusters.push_back(Cluster(i, std::make_shared<std::vector<Point>>()));
    // }

    // random assign
    int selection = pts->size() / numClusters;
    
    if (selection == 0) 
    {
        std::cerr << "Error: Not enough points for the number of clusters." << std::endl;
        return;
    }
    std::cout << "Cluster size: " << clusters.size() << std::endl;
    std::cout << "Selection: " << selection  << "num pts :" << pts->size() << std::endl;
    for(size_t i = 0; i < clusters.size(); ++i)
    {
        Cluster& currentCluster = clusters.at(i);
        std::cout << currentCluster.getCentroid() << std::endl;

        // for(size_t j = 0; j < pts->size(); ++j)
        // {
        //     if (j / selection < clusters.size())
        //     {
        //         // clusters.push_back(Cluster(i, {})); // segfalt
        //         currentCluster.assign(&(pts->at(j / selection)));
        //         std::cout << "Assigned point " << j << " to cluster " << i << std::endl;
        //     }
        //     else
        //     {
        //         std::cerr << "Error: Index out of bounds." << std::endl;
        //         return;
        //     }
        // }
        // clusters.at(i).computeCentroid();
    }
}

void KMeans::computeCentroids()
{
    // #pragma omp parallel for
    std::cout << "Cluster size " << clusters.size() << std::endl;
    for(size_t i = 0; i < clusters.size(); ++i)
    {
        clusters.at(i).computeCentroid();
        std::cout << "Centroid " << i << std::endl;
    }
}



void KMeans::assign()
{
    // #pragma omp parallel for
    for(size_t i = 0; i < pts->size(); ++i)
    {
        for(size_t j = 0; j < clusters.size(); ++j)
        {
            double dist = pts->at(i).dist(clusters.at(j).getCentroid());

            if(dist < pts->at(i).getDist())
                clusters.at(j).assign(&pts->at(i));
        }   
    }
}


void KMeans::write(std::string path)
{
    std::ofstream file;
    file.open(path);

    for(size_t i = 0; i < clusters.size(); ++i)
    {
        file << clusters.at(i).getCentroid() << "," << std::endl;
    }
    file.close();
}

void KMeans::clearClusters()
{
    for(size_t i = 0; i < clusters.size(); ++i)
    {
        clusters.at(i).clear();
    }
}

void KMeans::run()
{
    for(size_t it = 0; it < epochs; ++it)
    {
        std::cout<< "Epoch: " << it  << "/" << epochs << std::endl;
        
        assign();
        computeCentroids();
        clearClusters();
    }
    write("../data/centroids.csv");
}

