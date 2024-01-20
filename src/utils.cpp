#include "../include/utils.h"

std::vector<Point> Utils::readCsv(std::string path)
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
        // points.emplace_back(pid, features);
        points.emplace_back(features.at(0), features.at(1)); // for x,y coords
    }

    file.close();
    return points;
}

void Utils::writeCsv(const std::vector<Observation>& p, const std::string path)
{
    std::ofstream file;
    file.open(path);

    if (!file.is_open()) 
    {
        std::cerr << "Error opening file: " << path << std::endl;
    }
    std::cout<< "Writing to file " << path << std::endl;
    
    for(size_t i = 0; i < p.size(); ++i)
    {
        file << p.at(i).X() << ", " << p.at(i).Y() << ", ";
        file << p.at(i).getClusterID() << std::endl;
    }
    file.close();
}
