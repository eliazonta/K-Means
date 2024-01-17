#include <iostream>

#include "../include/point.h"

Point::Point():
    pointID(-1), clusterID(-1), distance(__DBL_MAX__){}

Point::Point(int cid):
    pointID(cid), clusterID(cid), distance(__DBL_MAX__){}

Point::Point(int pid, std::vector<double> f):
    pointID(pid), clusterID(-1), distance(__DBL_MAX__), features(f), dimensions(f.size()){}

Point::Point(const Point& p):
    pointID(p.pointID), clusterID(p.clusterID), distance(p.distance), features(p.features), dimensions(p.dimensions){}

double Point::dist(Point p)
{
    // Euclidean distance
    double sum = 0.0;
    for(size_t i = 0; i < features.size(); ++i)
    {
        sum += pow(this->features.at(i) - p.features.at(i), 2);
    }
    return sqrt(sum);
}

std::ostream& operator<<(std::ostream& os, const Point p)
{
    os << "Point " << p.pointID << ":\n";
    os << "Cluster: " << p.clusterID << "\n";
    os << "Distance: " << p.distance << "\n";
    os << "Features: ";
    for(size_t i = 0; i < p.features.size(); ++i)
    {
        os << p.features.at(i) << " ";
    }
    os << "\n";
    return os;
}
