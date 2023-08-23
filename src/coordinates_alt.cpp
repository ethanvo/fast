#include "coordinates.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<Atom> extractNuclearCoordinates(const std::string& filePath) {
    std::vector<Atom> nuclearCoords;

    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return nuclearCoords;
    }

    std::string line;
    bool readingCoordinates = false;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string keyword;
        iss >> keyword;

        if (keyword == "geometry") {
            readingCoordinates = true;
            continue;
        } else if (keyword == "end") {
            break; // Stop reading coordinates
        }

        if (readingCoordinates) {
            std::string symbol;
            double x, y, z;
            iss >> symbol >> x >> y >> z;

            if (!symbol.empty()) {
                nuclearCoords.push_back({symbol, x, y, z});
            }
        }
    }

    return nuclearCoords;
}

