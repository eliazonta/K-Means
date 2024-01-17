#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <memory>

#include "../include/point.h"
#include "../include/k-means.h"
#include "../include/readWrite.h"

int main(int argc, char** argv){
    // if(argc != 4){
    //     std::cout << "Usage " << argv[0] << " <dataset path> <N epochs> <K clusters>" << std::endl;
    //     exit(-1);
    // }else
    // {
        std::string path = "../data/UnDefined.csv"; //argv[1];
        std::vector<Point> points = readCsv(path);

        auto pts_ptr = std::make_shared<std::vector<Point>>(points);

        
        KMeans kmeans(pts_ptr, 10, 4);
        // int epochs = 10;    //atoi(argv[2]);
    //     int clusters = 4;   //atoi(argv[3]);
    
        clock_t start = clock();

        // try
        // {
        //     kmeans.run();
        // }
        // catch(const std::exception& e)
        // {
        //     std::cerr << e.what() << '\n';
        //     return EXIT_FAILURE;
        // }

		clock_t stop = clock();
        clock_t elapsed = (((float)(stop - start)) / CLOCKS_PER_SEC) * 1000; // s

    //     std::cout<< "[ K-Means clustering algorithm ]\n" <<
    //     			"-> Details : data [ " << path << "] | " << epochs << " epochs | " 
    //             << clusters << " clusters;" << std::endl;
    std::cout << "Run time : "<< elapsed << " s" << std::endl;
    std::cout << "Done." << std::endl;

    // POST CLUSTERING
    std::vector<Point>* p = pts_ptr.get();

    for (std::vector<Point>::iterator it = p->begin(); it != p->end(); ++it) 
    {
        for(size_t i = 0; i < it->getFeatures().size(); ++i)
        {
            std::cout << it->getFeatures()[i] << ", ";
        }
        std::cout << it->getCluster() << std::endl;
    }
    ///////////////////////////////////

    writeCsv(pts_ptr.get(), "../data/out.csv");
    // }
    return EXIT_SUCCESS;
}
