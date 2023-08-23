#ifndef SHELL_H
#define SHELL_H

#include "basis.h"

struct Shell {
	double* center;
	int l;
	int n_primitives;
	double* exponents;
	double* coefficients;
	// Spherical indices
	int* spherical_indices;
	// Cartesian indices
	int* cartesian_indices;
};

int getL(char l);

std::vector<Shell> formShells(std::vector<Atom> atoms, std::vector<BasisShell> basisSet);

#endif // SHELL_H
