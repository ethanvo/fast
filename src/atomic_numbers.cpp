#include "atomic_numbers.h"

#include <vector>

#include "atomic_info.h"
#include "coordinates.h"

// This function takes a vectors of Atom structs and returns a vector of atomic
// numbers. Uses getAtomicNumberFromSymbol() to convert the symbol to an atomic
// number.

std::vector<int> getAtomicNumbers(const std::vector<Atom>& atoms) {
  std::vector<int> atomicNumbers;
  for (const auto& atom : atoms) {
    atomicNumbers.push_back(getAtomicNumberFromSymbol(atom.symbol));
  }
  return atomicNumbers;
}
