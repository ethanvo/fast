#include "shell.h"
#include "basis.h"
#include "coordinates.h"

#include <vector>

// Map angular momemtum symbol to integer
int getl(const char& angularMomentumSymbol) {
	switch (angularMomentumSymbol) {
		case 'S':
			return 0;
		case 'P':
			return 1;
		case 'D':
			return 2;
		case 'F':
			return 3;
		case 'G':
			return 4;
		case 'H':
			return 5;
		case 'I':
			return 6;
		case 'J':
			return 7;
		case 'K':
			return 8;
		case 'L':
			return 9;
		case 'M':
			return 10;
		case 'N':
			return 11;
		case 'O':
			return 12;
		case 'Q':
			return 13;
		case 'R':
			return 14;
		case 'T':
			return 15;
		case 'U':
			return 16;
		case 'V':
			return 17;
		case 'W':
			return 18;
		case 'X':
			return 19;
		case 'Y':
			return 20;
		case 'Z':
			return 21;
		default:
			return -1;
	}
}

// Function that takes in vector of atoms and the basis set and returns a vector of shells.
// Populating their center, angular momentum l, number of primitives, linking their exponents and coefficients and populating their spherical and cartesian indices.
std::vector<Shell> formShells(std::vector<Atom> atoms, std::vector<BasisShell> basisSet) {
	std::vector<Shell> shells;
	int spherical_count = 0;
	int cartesian_count = 0;
	for (const Atom& atom: atoms) {
		for (const BasisShell& basisShell: basisSet) {
			if (atom.symbol == basisShell.symbol) {
				Shell shell;
				shell.center = new double[3];
				shell.center[0] = atom.x;
				shell.center[1] = atom.y;
				shell.center[2] = atom.z;
				int l = getl(basisShell.l);
				shell.l = l;
				shell.n_primitives = basisShell.n_primitives;
				shell.exponents = basisShell.exponents;
				shell.coefficients = basisShell.coefficients;
				shell.spherical_indices = new int[2*l+1];
				shell.cartesian_indices = new int[(l+1)*(l+2)/2];
				for (int i = 0; i < 2*l+1; i++) {
					shell.spherical_indices[i] = spherical_count;
					spherical_count++;
				}
				for (int i = 0; i < (l+1)*(l+2)/2; i++) {
					shell.cartesian_indices[i] = cartesian_count;
					cartesian_count++;
				}
				shells.push_back(shell);
			}
		}
	}
	return shells;
}
