#include "simple_lib.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
	// Load the JSON file
	std::cout << "Loading JSON file..." << std::endl;
	std::ifstream f("water.json");
	json data = json::parse(f);
	// Iterates through the data["geometry"] array and prints the coordinates
	for (auto& element : data["geometry"]) {
		std::cout << element << std::endl;
	}
	// Make an array of atomic symbols frrom data["geometry"]
	std::vector<std::string> symbols;
	for (auto& element : data["geometry"]) {
		symbols.push_back(element[0]);
	}
	// Print the array of atomic symbols
	std::cout << "Atomic symbols: " << std::endl;
	for (auto& element : symbols) {
		std::cout << element << std::endl;
	}
	// Make an array of atomic coordinates from data["geometry"]
	std::vector<std::vector<double>> coords;
	for (auto& element : data["geometry"]) {
		coords.push_back(element[1]);
	}
	// Print the array of atomic coordinates
	std::cout << "Atomic coordinates: " << std::endl;
	for (auto& element : coords) {
		for (auto& coord : element) {
			std::cout << coord << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
  std::cout << simple_lib_function() << std::endl;
  return 0;
}
