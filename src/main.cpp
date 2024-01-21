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
    if(argc != 3){
        std::cout << "Usage " << argv[0] << " <dataset path> <K clusters>" << std::endl;
        return EXIT_FAILURE;
    }else
    {
        std::string path = argv[1];
        auto points = Utils::readCsv(path);

        const auto clusters = atoi(argv[2]);
    
        constexpr double tolerance = 0.001;
        constexpr unsigned int epochs = 1000;


#if SHOW_DETAILS
        std::cout << "Points number: " << points.size() << std::endl;
        const auto observationWithIteration = KMeans::fit(points, clusters, tolerance, epochs);
        const auto centroids = std::get<0>(observationWithIteration);
        for (auto &c : centroids)
            std::cout << c.getX() << " " << c.getY() << '\n';
#endif
        const auto elapsed = measure<micros>::measure_time(KMeans::fit, points, clusters, tolerance, epochs)
                                  .first
                                  .count();
        std::cout << static_cast<double>(elapsed) / 1000 << std::endl;

        std::cout << "Done.\n Exiting..." << std::endl;

        // Utils::writeCsv(pts_ptr.get(), "../data/out.csv");
    }
    return EXIT_SUCCESS;
}
