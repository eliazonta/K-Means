#include <iostream>
#include <time.h>
#include <vector>
#include <string>
// #include <memory>

#include "../include/point.h"
#include "../include/k-means.h"
#include "../include/utils.h"

#define SHOW_DETAILS false

int main(int argc, char** argv)
{
    if(argc != 4){
        std::cout << "Usage " << argv[0] << " <dataset path> <N epochs> <K clusters>" << std::endl;
        exit(-1);
    }else
    {
        std::string path = "../data/UnDefined.csv"; //argv[1];
        std::vector<Point> points = Utils::readCsv(path);

        // auto pts_ptr = std::make_shared<std::vector<Point>>(points);

        

        const auto clusters = atoi(argv[3]);
    
        constexpr double tolerance = 0.001;
        constexpr int epochs = 1000;


#if SHOW_DETAILS
        const auto observationWithIteration = KMeans::fit(points, clusters, tolerance, epochs);
        const auto centroids = std::get<0>(observationWithIteration);
        for (auto &c : centroids)
            std::cout << c.getX() << " " << c.getY() << '\n';
#endif
        const auto elapsed = measure<micros>::measure_time(KMeans::fit, points, clusters, tolerance, epochs)
                                  .first
                                  .count();
        std::cout << static_cast<double>(elapsed) / 1000 << std::endl;

        std::cout << "Done." << std::endl;

        // Utils::writeCsv(pts_ptr.get(), "../data/out.csv");
    }
    return EXIT_SUCCESS;
}
