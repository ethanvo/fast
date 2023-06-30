#include "basis.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<Basis> extractBasis(const std::string& filePath) {
	std::vector<Basis> basis;

	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Could not open file " << filePath << std::endl;
		return basis;
	}

	std::string line;
	bool readBasis = false; // Flag to indicate when to start reading basis
	
	while (std::getline(inputFile, line)) {
	}
}
