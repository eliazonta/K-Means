#include <iostream>
#include <time.h>
#include <vector>
#include <string>

#include "../include/Point.h"
#include "../include/k-means.h"
#include "../include/readWrite.h"

int main(int argc, char** argv){
    if(argc != 4){
        std::cout << "Usage " << argv[0] << " <dataset path> <N epochs> <K clusters>" << std::endl;
        exit(-1);
    }else{
        std::string path = argv[1];
        int epochs = atoi(argv[2]);
        int clusters = atoi(argv[3]);
        std::vector<Point> points = readCsv(path);
        clock_t start = clock();
        try
        {
            KMeans(&points, epochs, clusters);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return EXIT_FAILURE;
        }
        clock_t stop = clock();
        clock_t elapsed = (((float)(stop - start)) / CLOCKS_PER_SEC) * 1000; // ms
        std::cout<< "[ K-Means clustering algorithm ]" << std::endl;
        std::cout<< "-> Details : data [ " << path << "] | " << epochs << " epochs | " 
                << clusters << " clusters;" << std::endl;
        std::cout << "Sequential running time : "<< elapsed << " ms" << std::endl;
        writeCsv(&points, "data/out.csv");
    }
    return EXIT_SUCCESS;
}