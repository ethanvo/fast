#include "simple_lib.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

int main() {
  std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
  std::cout << simple_lib_function() << std::endl;
  return 0;
}
