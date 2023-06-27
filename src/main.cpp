#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include "../include/Point.h"
#include "../include/k-means.h"
#include "../include/readWrite.h"

int main(int argc, char** argv){
    if(argc != 4){
        std::cout << "Usage ./K-Means <dataset path> <N epochs> <K clusters>" << std::endl;
        exit(-1);
    }else{
        std::string path = argv[1];
        int epochs = atoi(argv[2]);
        int clusters = atoi(argv[3]);
        std::vector<Point> points = readCsv(path);
        try
        {
            KMeans(&points, epochs, clusters);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return EXIT_FAILURE;
        }
        writeCsv(&points, "data/out.csv");
    }
    return EXIT_SUCCESS;
}