#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include "Point.hpp"
#include "k-means.hpp"
#include "readWrite.hpp"

int main(int argc, char** argv){
    std::vector<Point> points = readCsv("data/data.csv");
    try
    {
        KMeans(&points, 100, 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    writeCsv(&points, "data/out.csv");
    return EXIT_SUCCESS;
}