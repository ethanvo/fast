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
  bool readCoordinates =
      false;  // Flag to indicate when to start reading coordinates

  while (std::getline(inputFile, line)) {
    std::istringstream iss(line);
    std::string keyword;
    iss >> keyword;

    if (keyword == "geometry") {
      readCoordinates = true;
      continue;
    } else if (keyword == "end") {
      break;  // Stop reading coordinates
    }

    if (readCoordinates) {
      std::istringstream coordIss(line);
      std::string symbol;
      double x, y, z;
      coordIss >> symbol >> x >> y >> z;

      if (!symbol.empty()) {
        nuclearCoords.push_back({symbol, x, y, z});
      }
    }
  }

  inputFile.close();
  return nuclearCoords;
}
