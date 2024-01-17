#pragma once
#ifndef __READWRITE__
#define __READWRITE__
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "point.h"

std::vector<Point> readCsv(std::string path);

void writeCsv(std::vector<Point>* p, std::string s);

#endif
