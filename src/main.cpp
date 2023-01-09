#include "simple_lib.hpp"
#include "sub_lib.hpp" 
#include "atomic_map_lib.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
	
	// Load the JSON file
	std::cout << "Loading JSON file..." << std::endl;
	std::ifstream f("/Users/ethanvo/builds/fast/water.json");
	json data = json::parse(f);

	// Iterates through the data["geometry"] array and prints the coordinates
	for (auto& element : data["geometry"]) {
		std::cout << element << std::endl;
	}

	// Make an array of atomic symbols from data["geometry"]
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

	// Create a vector of atomic numbers from the symbols vector
	std::vector<int> atomic_numbers;
  atomic_numbers = get_atomic_numbers(symbols);

	// Print the atomic numbers
	for (int i = 0; i < atomic_numbers.size(); i++) {
		std::cout << atomic_numbers[i] << std::endl;
	}

	// Find unique atomic numbers in atomic_numbers using set
	std::set<int> unique_atomic_numbers;
	unique_atomic_numbers = get_unique_atomic_numbers(atomic_numbers);

	// Print the unique atomic numbers
	std::cout << "Unique atomic numbers: " << std::endl;
	for (auto& element : unique_atomic_numbers) {
		std::cout << element << std::endl;
	}

	// Print data dictionary keys
	std::cout << "Data dictionary keys: " << std::endl;
	for (auto& element : data.items()) {
		std::cout << element.key() << std::endl;
	}

	// Print data dictionary values
	std::cout << "Data dictionary values: " << std::endl;
	for (auto& element : data.items()) {
		std::cout << element.value() << std::endl;
	}

	// Count the number of shells
	int n_shells = 0;
	for (auto& element : atomic_numbers) {
		for (int i = 0; i < data["elements"][std::to_string(element)]["electron_shells"].size(); i++) {
			n_shells += data["elements"][std::to_string(element)]["electron_shells"][i]["angular_momentum"].size() * data["elements"][std::to_string(element)]["electron_shells"][i]["coefficients"].size();
		}
	}

	// Print the number of shells
	std::cout << "Number of shells: " << n_shells << std::endl;

	// Print the coefficients and the respective exponent.
	// If the coefficient is zero, remove the coefficient and exponent from the array.
	
	for (auto& element : atomic_numbers) {
		std::cout << "Element: " << element << std::endl;
		for (int i = 0; i < data["elements"][std::to_string(element)]["electron_shells"].size(); i++) {
			for (int j = 0; j < data["elements"][std::to_string(element)]["electron_shells"][i]["coefficients"].size(); j++) {
				std::cout << "Shell: " << j << std::endl;
				for (int l = 0; l < data["elements"][std::to_string(element)]["electron_shells"][i]["angular_momentum"].size(); l++) {
					int angular_momentum = data["elements"][std::to_string(element)]["electron_shells"][i]["angular_momentum"][l];
					std::cout << "Angular momentum: " << angular_momentum << std::endl;
					for (int k = 0; k < data["elements"][std::to_string(element)]["electron_shells"][i]["coefficients"][j].size(); k++) {
						std::string coefficient = data["elements"][std::to_string(element)]["electron_shells"][i]["coefficients"][j][k];
						double coefficient_double = std::stod(coefficient);
						if (coefficient_double != 0) {
							std::string exponent = data["elements"][std::to_string(element)]["electron_shells"][i]["exponents"][k];
							double exponent_double = std::stod(exponent);
							std::cout << "Exponent: " << exponent_double << " Coefficient: " << coefficient_double << std::endl;
						}
					}
				}
			}
		}
	}

	std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
  std::cout << simple_lib_function() << std::endl;

	std::cout << "Sub Directory example C++ compiled correctly and ran." << std::endl;
	std::cout << sub_lib_function() << std::endl;
  
	return 0;
}
