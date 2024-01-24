#include <iostream>

#include "../include/point.h"

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point& p): x(p.x), y(p.y) {}

double Point::distance(const Point &p1, const Point &p2)
{
    const auto x = p1.X() - p2.Y();
    const auto y = p1.X() - p2.Y();
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

// double Point::distance(const Point &p1, const Point &p2)
// {
//     // Euclidean distance
//     double sum = 0.0;
//     for (const auto &f : p1.features.size() - 1)
//     {
//         sum += pow(p1.features.at(i) - p2.features.at(i), 2);
//     }
//     return std::sqrt(sum);
// }

Observation::Observation(double x, double y, int k) : Point(x, y), clusterID(k) {}

std::ostream &operator<<(std::ostream &os, const Observation &ob)
{
    os << "[" << ob.X() << "," << ob.Y() << "]  id = " << ob.getClusterID();
    return os;
}