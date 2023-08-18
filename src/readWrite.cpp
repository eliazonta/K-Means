#include "../include/readWrite.h"

std::vector<Point> readCsv(std::string path){
    std::vector<Point> points;
    std::ifstream file(path);
    std::string s; 

    while(getline(file, s)){
        std::stringstream ss(s);
        std::string token;
        double x, y, z;
        getline(ss, token, ',');
        x = std::stof(token);
        getline(ss, token, ',');
        y = std::stof(token);
        getline(ss, token, '\n');
        z = std::stof(token);
        points.push_back(Point(x, y, z));
    }
    return points;
}

void writeCsv(std::vector<Point>* p, std::string s){
    std::ofstream file;
    file.open(s);
    file << "x, y, z, K" << std::endl;
    for (std::vector<Point>::iterator it = p->begin(); it != p->end(); ++it) {
        file << it->getX() << ", " << it->getY() << ", " << it->getZ() <<", " << it->getK() << std::endl;
    }
    file.close();
}
