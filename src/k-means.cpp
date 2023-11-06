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


void KMeans(std::vector<Point>* p,int epochs, int k){
    std::vector<Point> centroids;
    std::srand(time(nullptr));
    std::vector<int> npts(k, 0);
    std::vector<double> sx(k, 0.0), sy(k, 0.0), sz(k, 0.0);    //cumulative x, y, x

    #ifdef DEBUG
        std::cout << "=== DEBUG ===" << std::endl;
    #endif

    // init clusters with some random point
    // omp_set_num_threads(k);
    #pragma omp parallel num_threads(k)
    {
	#ifdef DEBUG
		std::cout << "N threads : [" << omp_get_num_threads() << "]\n"; 
	#endif
    #pragma omp for 
    for(size_t i = 0; i < k; i++){
        centroids.push_back(p->at(rand() % p->size()));
    }

    for(size_t it = 0; it < epochs; ++it)
    {

        #ifdef DEBUG
        std::cout << "epoch - " << it << "/" << epochs << std::endl; 
        #endif

        // assign pts to a cluster
		size_t j;
        #pragma omp for private(j) 
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
                    p->at(j).K(i);
                    #ifdef DEBUG
                    std::cout<<"Point N: [" << j  << "] "<< "re-assigned at K: [" << p->at(j).getK() << "]" <<std::endl; 
                    #endif
                }
            }
        }
        // new centroids 
        #pragma omp for
        for(size_t i = 0; i < p->size(); ++i)
        {
            size_t id = p->at(i).K();
            #pragma omp atomic
            npts[id]++;
            #pragma omp atomic
            sx[id] += p->at(i).X();
            #pragma omp atomic
            sy[id] += p->at(i).Y();
            #pragma omp atomic
            sz[id] += p->at(i).Z();
            p->at(i).setMinDist(__DBL_MAX__); // reset
        }

        //compute new centroids
		omp_set_num_threads(centroids.size());
		int cthreads = omp_get_num_threads();
        
		#ifdef DEBUG
		std::cout << "N cthreads : [" << cthreads << std::cout << "]\n";
		#endif

		#pragma omp for 
        for(size_t i = 0;i < centroids.size(); ++i)
        {
            centroids.at(i).X(sx[i] / npts[i]);
            centroids.at(i).Y(sy[i] / npts[i]);
            centroids.at(i).Z(sz[i] / npts[i]);
            centroids.at(i).K(i);
        }
    }
    }
    writeCsv(&centroids, "data/centroids.csv");
}
