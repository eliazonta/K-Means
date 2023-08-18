/*
    flow :
    random clusters init
    for e in EPOCHS
        assign points to clusters 
        compute centrods for each cluster
        update centroids 
*/

#include "../include/k-means.h"
#include <omp.h>
// #define DEBUG
//#define OMP

void KMeans(std::vector<Point>* p,int epochs, int k){
    std::vector<Point> centroids;
    std::srand(time(nullptr));
    std::vector<int> npts(p->size());
    std::vector<double> sx(k), sy(k), sz(k);    //cumulative x, y, x 
    #ifdef DEBUG
        std::cout << "=== DEBUG ===" << std::endl;
    #endif
    // init clusters with some random point
    #ifdef OMP
    // omp_set_num_threads(k);
    #pragma omp num_threads(k)
	#ifdef DEBUG
		std::cout << "N threads : [" << omp_get_num_threads() << "]\n"; 
	#endif
    #pragma omp parallel for 
    #endif
    for(size_t i = 0; i < k; i++){
        centroids.push_back(p->at(rand() % p->size()));
        npts.at(i) = 0;  
        sx.at(i) = 0.0;
        sy.at(i) = 0.0;
        sz.at(i) = 0.0;
    }
    for(size_t it = 0; it < epochs; ++it)
    {
        #ifdef DEBUG
        std::cout << "epoch - " << it << "/" << epochs << std::endl; 
        #endif
        // assign pts to a cluster
		size_t j;
        #ifdef OMP
        #pragma omp parallel for private(j) 
        #endif
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
		#ifdef OMP
		omp_set_num_threads(centroids.size());
		int cthreads = omp_get_num_threads();
		#ifdef DEBUG
		std::cout << "N cthreads : [" << cthreads << std::cout << "]\n";
		#endif
		#pragma omp parallel for 
		#endif
        for(size_t i = 0;i < centroids.size(); ++i)
        {
            centroids.at(i).setX(sx[i] / npts[i]);
            centroids.at(i).setY(sy[i] / npts[i]);
            centroids.at(i).setZ(sz[i] / npts[i]);
            centroids.at(i).setK(i);
        }
    }
    writeCsv(&centroids, "data/centroids.csv");
}
