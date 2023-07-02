/*
    flow :
    random clusters init
    for e in EPOCHS
        assign points to clusters 
        compute centrods for each cluster
        update centroids 
*/

#include "../include/k-means.h"
// #define DEBUG

void KMeans(std::vector<Point>* p,int epochs, int k){
    std::vector<Point> centroids;
    std::srand(time(nullptr));
    std::vector<int> npts(p->size());
    std::vector<double> sx(k), sy(k), sz(k);
    #ifdef DEBUG
        std::cout << "=== DEBUG ===" << std::endl;
    #endif
    // init clusters with some random point
    for(size_t i = 0; i < k; i++){
        centroids.push_back(p->at(rand() % p->size()));
        npts.at(i) = 0;  
        sx.at(i) = 0.0;
        sy.at(i) = 0.0;
        sz.at(i) = 0.0;
    }
    for(size_t it = 0; it < epochs; ++it)
    {
        // assign pts to a cluster
        for(size_t i = 0; i < centroids.size(); ++i)
        {
            #ifdef DEBUG
            std::cout<<"centroid N: [" << i << "]" << std::endl; 
            #endif
            for(size_t j = 0;j < p->size(); ++j)
            {
                #ifdef DEBUG
                std::cout<<"Point N: [" << j << "]" << std::endl; 
                #endif
                double dist = p->at(j).dist(centroids.at(i));
                if(dist < p->at(j).getMinDist()){
                    p->at(j).setMinDist(dist);
                    p->at(j).setK(i);
                    #ifdef DEBUG
                    std::cout<<"Point N: [" << j  << "] "<< "re-assigned at K: [" << p->at(j).getK() << "]" <<std::endl; 
                    #endif
                }
            }
        }
        // new centroids 
        for(size_t i = 0; i < p->size(); ++i)
        {
            size_t id = p->at(i).getK();
            npts[id]++;
            sx[id] += p->at(i).getX();
            sy[id] += p->at(i).getY();
            sz[id] += p->at(i).getZ();
            p->at(i).setMinDist(__DBL_MAX__); // reset
        }
        //compute new centroids
        for(size_t i = 0;i < centroids.size(); ++i)
        {
            centroids.at(i).setX(sx[i] / npts[i]);
            centroids.at(i).setY(sy[i] / npts[i]);
            centroids.at(i).setZ(sz[i] / npts[i]);
        }
    }
    writeCsv(&centroids, "data/centroids.csv");
}