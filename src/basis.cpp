#include "basis.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void addShell(std::vector<BasisShell>& basisFunctions,
              const std::string& symbol, char l, std::vector<double>& exponents,
              std::vector<double>& coefficients) {
  BasisShell shell;
  shell.symbol = symbol;
  shell.l = l;
  shell.n_primitives = exponents.size();
  shell.exponents = new double[shell.n_primitives];
  shell.coefficients = new double[shell.n_primitives];
  for (int i = 0; i < shell.n_primitives; i++) {
    shell.exponents[i] = exponents[i];
    shell.coefficients[i] = coefficients[i];
  }
  basisFunctions.push_back(shell);
  exponents.clear();
  coefficients.clear();
}

std::vector<BasisShell> extractBasisSet(const std::string& filePath) {
  std::vector<BasisShell> basisSet;
  std::ifstream inputFile(filePath);

  if (!inputFile) {
    std::cerr << "Error opening file: " << filePath << std::endl;
    return basisSet;
  }

  std::string line;
  bool readingBasis = false;
  bool basisOpen = false;
  std::string symbol;
  char l;
  double exponent;
  double coefficient;
  std::vector<double> exponents;
  std::vector<double> coefficients;
  std::string temp0;
  std::string temp1;

  while (std::getline(inputFile, line)) {
    std::istringstream iss(line);
    std::istringstream basisIss(line);
    std::string keyword;
    iss >> keyword;

    if (keyword == "basis") {
      readingBasis = true;
      continue;
    } else if (keyword == "end" && readingBasis) {
      addShell(basisSet, symbol, l, exponents, coefficients);
      break;
    }

    // Read in basis set
    if (readingBasis) {
      basisIss >> temp0 >> temp1;
      if (isalpha(temp0[0])) {
        if (basisOpen) {
          addShell(basisSet, symbol, l, exponents, coefficients);
        }
        std::istringstream symbolIss(line);
        symbolIss >> symbol >> temp1;
        l = temp1[0];
        basisOpen = true;
      } else {
        std::istringstream exponentIss(line);
        exponentIss >> exponent >> coefficient;
        exponents.push_back(exponent);
        coefficients.push_back(coefficient);
      }
    }
  }

  return basisSet;
}
