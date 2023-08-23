#include <iostream>
#include <string>
#include <vector>

#include "atomic_numbers.h"
#include "basis.h"
#include "coordinates.h"
#include "shell.h"

int main() {
  std::string filePath = "/Users/ethanvo/builds/fast/water.nw";
  std::vector<Atom> nuclearCoords = extractNuclearCoordinates(filePath);

  if (!nuclearCoords.empty()) {
    std::cout << "Nuclear Coordinates:\n";
    for (const Atom& atom : nuclearCoords) {
      std::cout << atom.symbol << " " << atom.x << " " << atom.y << " "
                << atom.z << std::endl;
    }
  } else {
    std::cout << "No nuclear coordinates found in the input file.\n";
  }
  std::cout << "Reading Basis Set" << std::endl;

  std::vector<BasisShell> basisSet = extractBasisSet(filePath);

  for (const BasisShell& shell : basisSet) {
    std::cout << shell.symbol << " " << shell.l << std::endl;
    for (int i = 0; i < shell.n_primitives; i++) {
      std::cout << shell.exponents[i] << " " << shell.coefficients[i]
                << std::endl;
    }
  }

	// Form shells
	std::vector<Shell> shells = formShells(nuclearCoords, basisSet);
	for (const Shell& shell: shells) {
		std::cout << "Shell Center: " << shell.center[0] << " " << shell.center[1] << " " << shell.center[2] << std::endl;
		std::cout << "Shell l: " << shell.l << std::endl;
		std::cout << "Shell n_primitives: " << shell.n_primitives << std::endl;
		std::cout << "Shell exponents and coefficients: " << std::endl;
		for (int i = 0; i < shell.n_primitives; i++) {
			std::cout << shell.exponents[i] << " " << shell.coefficients[i] << std::endl;
		}
		std::cout << "Shell spherical indices: " << std::endl;
		for (int i = 0; i < 2*shell.l+1; i++) {
			std::cout << shell.spherical_indices[i] << std::endl;
		}
		std::cout << "Shell cartesian indices: " << std::endl;
		for (int i = 0; i < (shell.l+1)*(shell.l+2)/2; i++) {
			std::cout << shell.cartesian_indices[i] << std::endl;
		}
	}

  return 0;
}
