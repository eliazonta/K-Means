#include "../include/readWrite.h"

std::vector<Point> readCsv(std::string path)
{
    std::vector<Point> points;
    std::ifstream file(path);
    

    if (!file.is_open()) 
    {
        std::cerr << "Error opening file: " << path << std::endl;
        return points;
    }

    std::string line;
    int lineCount = 0;

    while(getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> tokens;

        while (getline(iss, line, ',')) 
        {
            tokens.push_back(line);
        }

        std::vector<double> features;
        for (size_t i = 0; i < tokens.size(); ++i) 
        {
            features.push_back(std::stod(tokens[i]));
        }
        int pid = lineCount++;
        // Create a Point object and add it to the vector
        points.emplace_back(pid, features);
    }

    file.close();
    return points;
}

void writeCsv(std::vector<Point>* p, std::string path)
{
    std::ofstream file;
    file.open(path);

    if (!file.is_open()) 
    {
        std::cerr << "Error opening file: " << path << std::endl;
    }

    for (std::vector<Point>::iterator it = p->begin(); it != p->end(); ++it) 
    {
        for(size_t i = 0; i < it->getFeatures().size(); ++i)
        {
            file << it->getFeatures()[i] << ", ";
        }
        file << it->getCluster() << std::endl;
    }
    file.close();
}
