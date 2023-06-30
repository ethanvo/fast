#ifndef COORDINATES_H
#define COORDINATES_H

#include <string>
#include <vector>

struct Atom {
    std::string symbol;
    double x, y, z;
};

std::vector<Atom> extractNuclearCoordinates(const std::string& filePath);

#endif // COORDINATES_H
