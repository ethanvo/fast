#ifndef BASIS_H
#define BASIS_H

#include <string>
#include <vector>

#include "coordinates.h"

struct BasisShell {
  // symbol
  std::string symbol;
  // angular momentum
  char l;
  // number of primitives
  int n_primitives;
  // exponents
  double* exponents;
  // coefficients
  double* coefficients;
};

void addShell(std::vector<BasisShell>& basisFunctions,
              const std::string& symbol, char l, std::vector<double>& exponents,
              std::vector<double>& coefficients);

std::vector<BasisShell> extractBasisSet(const std::string& filePath);

#endif  // BASIS_H:w
        //
