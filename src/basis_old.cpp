#include "coordinates.h"
#include "basis.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Function takes in vector of Atoms and input file path and returns a shell vector
std::vector<Shell> extractBasisFunctions(const std::vector<Atom>& nuclearCoords, const std::string& filePath) {
	std::vector<Shell> basisFunctions;

	std::ifstream basisFile(filePath);
	// Check if file exists
	if (!basisFile) {
		std::cout << "File does not exist" << std::endl;
		exit(1);
	}
	// In the basis section of basisFile, find shells that match the atomic symbol and print them
	std::string line;
	for (const Atom& atom : nuclearCoords) {
		while (std::getline(basisFile, line)) {
			// Find the "basis" section of the file
			if (line.find("basis") != std::string::npos) {
				while (std::getline(basisFile, line)) {
					bool foundShell = false;
					if (line.find(atom.symbol) != std::string::npos) {
						std::cout << line << std::endl;
						foundShell = true;
					}
					if (line.find("end") != std::string::npos) {
						break;
					}
				}
			}
		}
		basisFile.clear();
		basisFile.seekg(0, std::ios::beg);
	}
	return basisFunctions;
}
