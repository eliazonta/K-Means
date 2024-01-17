#include "../include/cluster.h"
#include <omp.h>
// #define DEBUG

Cluster::Cluster(): clusterID(cid++), centroid(cid), pts(){}

Cluster::Cluster(std::shared_ptr<std::vector<Point>> p): 
    clusterID(cid++), pts(p), cumulative(p->at(0).getFeatures().size(), 0.0){}

Cluster::Cluster(const Cluster& c): 
    clusterID(c.clusterID), centroid(c.centroid), pts(c.pts), cumulative(c.cumulative){}



void Cluster::assign(std::shared_ptr<std::vector<Point>> p, int i)
{
    p->at(i).dist(p->at(i).dist(centroid));
    p->at(i).setCluster(clusterID);
    // pts->push_back(p->at(i));
}

void Cluster::computeCentroid()
{
    for(size_t i = 0; i < pts->size(); ++i)
    {
        for(size_t j = 0; j < pts->at(i).getFeatures().size(); ++j)
        {
            cumulative.at(j) += pts->at(i).getFeatures()[j];
        }
    }
    // divide each cumulative by the number of points in the cluster
    for(size_t i = 0; i < cumulative.size(); ++i)
    {
        cumulative.at(i) /= pts->size();
    }
    centroid = Point(clusterID, cumulative);
    std::cout << "Centroid: " << centroid << std::endl;
}