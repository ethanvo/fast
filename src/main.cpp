#include <iostream>
#include "coordinates.h"
#include "atomic_numbers.h"

int main() {
    std::string filePath = "/Users/ethanvo/builds/fast/water.nw";
    std::vector<Atom> nuclearCoords = extractNuclearCoordinates(filePath);

    if (!nuclearCoords.empty()) {
        std::cout << "Nuclear Coordinates:\n";
        for (const auto& atom : nuclearCoords) {
            std::cout << atom.symbol << " " << atom.x << " " << atom.y << " " << atom.z << std::endl;
        }
    } else {
        std::cout << "No nuclear coordinates found in the input file.\n";
    }

		std::vector<int> atomicNumbers = getAtomicNumbers(nuclearCoords);
		if (!atomicNumbers.empty()) {
			std::cout << "Atomic Numbers:\n";
			for (const auto& atomicNumber : atomicNumbers) {
				std::cout << atomicNumber << std::endl;
			}
		} else {
			std::cout << "No atomic numbers found in the input file.\n";
		}

		// Number of electrons = sum of atomic numbers
		int numElectrons = 0;
		for (const auto& atomicNumber : atomicNumbers) {
			numElectrons += atomicNumber;
		}
		std::cout << "Number of electrons: " << numElectrons << std::endl;

    return 0;
}

