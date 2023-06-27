#ifndef __KMEANS__
#define __KMEANS__

#include <vector>
#include "Point.h"
#include "readWrite.h"
#include <iostream> // debug

void KMeans(std::vector<Point>* p,int epochs, int k);

#endif