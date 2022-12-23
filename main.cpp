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
  
	// Create a map of atomic symbols and atomic numbers
	std::map<std::string, int> atomic_numbers;
	atomic_numbers["H"] = 1;
	atomic_numbers["He"] = 2;
	atomic_numbers["Li"] = 3;
	atomic_numbers["Be"] = 4;
	atomic_numbers["B"] = 5;
	atomic_numbers["C"] = 6;
	atomic_numbers["N"] = 7;
	atomic_numbers["O"] = 8;
	atomic_numbers["F"] = 9;
	atomic_numbers["Ne"] = 10;
	atomic_numbers["Na"] = 11;
	atomic_numbers["Mg"] = 12;
	atomic_numbers["Al"] = 13;
	atomic_numbers["Si"] = 14;
	atomic_numbers["P"] = 15;
	atomic_numbers["S"] = 16;
	atomic_numbers["Cl"] = 17;
	atomic_numbers["Ar"] = 18;
	atomic_numbers["K"] = 19;
	atomic_numbers["Ca"] = 20;
	atomic_numbers["Sc"] = 21;
	atomic_numbers["Ti"] = 22;
	atomic_numbers["V"] = 23;
	atomic_numbers["Cr"] = 24;
	atomic_numbers["Mn"] = 25;
	atomic_numbers["Fe"] = 26;
	atomic_numbers["Co"] = 27;
	atomic_numbers["Ni"] = 28;
	atomic_numbers["Cu"] = 29;
	atomic_numbers["Zn"] = 30;
	atomic_numbers["Ga"] = 31;
	atomic_numbers["Ge"] = 32;
	atomic_numbers["As"] = 33;
	atomic_numbers["Se"] = 34;
	atomic_numbers["Br"] = 35;
	atomic_numbers["Kr"] = 36;
	atomic_numbers["Rb"] = 37;
	atomic_numbers["Sr"] = 38;
	atomic_numbers["Y"] = 39;
	atomic_numbers["Zr"] = 40;
	atomic_numbers["Nb"] = 41;
	atomic_numbers["Mo"] = 42;
	atomic_numbers["Tc"] = 43;
	atomic_numbers["Ru"] = 44;
	atomic_numbers["Rh"] = 45;
	atomic_numbers["Pd"] = 46;
	atomic_numbers["Ag"] = 47;
	atomic_numbers["Cd"] = 48;
	atomic_numbers["In"] = 49;
	atomic_numbers["Sn"] = 50;
	atomic_numbers["Sb"] = 51;
	atomic_numbers["Te"] = 52;
	atomic_numbers["I"] = 53;
	atomic_numbers["Xe"] = 54;
	atomic_numbers["Cs"] = 55;
	atomic_numbers["Ba"] = 56;
	atomic_numbers["La"] = 57;
	atomic_numbers["Ce"] = 58;
	atomic_numbers["Pr"] = 59;
	atomic_numbers["Nd"] = 60;
	atomic_numbers["Pm"] = 61;
	atomic_numbers["Sm"] = 62;
	atomic_numbers["Eu"] = 63;
	atomic_numbers["Gd"] = 64;
	atomic_numbers["Tb"] = 65;
	atomic_numbers["Dy"] = 66;
	atomic_numbers["Ho"] = 67;
	atomic_numbers["Er"] = 68;
	atomic_numbers["Tm"] = 69;
	atomic_numbers["Yb"] = 70;
	atomic_numbers["Lu"] = 71;
	atomic_numbers["Hf"] = 72;
	atomic_numbers["Ta"] = 73;
	atomic_numbers["W"] = 74;
	atomic_numbers["Re"] = 75;
	atomic_numbers["Os"] = 76;
	atomic_numbers["Ir"] = 77;
	atomic_numbers["Pt"] = 78;
	atomic_numbers["Au"] = 79;
	atomic_numbers["Hg"] = 80;
	atomic_numbers["Tl"] = 81;
	atomic_numbers["Pb"] = 82;
	atomic_numbers["Bi"] = 83;
	atomic_numbers["Po"] = 84;
	atomic_numbers["At"] = 85;
	atomic_numbers["Rn"] = 86;
	atomic_numbers["Fr"] = 87;
	atomic_numbers["Ra"] = 88;
	atomic_numbers["Ac"] = 89;
	atomic_numbers["Th"] = 90;
	atomic_numbers["Pa"] = 91;
	atomic_numbers["U"] = 92;
	atomic_numbers["Np"] = 93;
	atomic_numbers["Pu"] = 94;
	atomic_numbers["Am"] = 95;
	atomic_numbers["Cm"] = 96;
	atomic_numbers["Bk"] = 97;
	atomic_numbers["Cf"] = 98;
	atomic_numbers["Es"] = 99;
	atomic_numbers["Fm"] = 100;
	atomic_numbers["Md"] = 101;
	atomic_numbers["No"] = 102;
	atomic_numbers["Lr"] = 103;
	atomic_numbers["Rf"] = 104;
	atomic_numbers["Db"] = 105;
	atomic_numbers["Sg"] = 106;
	atomic_numbers["Bh"] = 107;
	atomic_numbers["Hs"] = 108;
	atomic_numbers["Mt"] = 109;
	atomic_numbers["Ds"] = 110;
	atomic_numbers["Rg"] = 111;
	atomic_numbers["Cn"] = 112;
	atomic_numbers["Nh"] = 113;
	atomic_numbers["Fl"] = 114;
	atomic_numbers["Mc"] = 115;
	atomic_numbers["Lv"] = 116;
	atomic_numbers["Ts"] = 117;
	atomic_numbers["Og"] = 118;

	// Use the map to create an array of atomic numbers from the symbols vector
	std::vector<int> atomic_numbers_vector;
	for (int i = 0; i < symbols.size(); i++) {
		atomic_numbers_vector.push_back(atomic_numbers[symbols[i]]);
	}

	// Print the atomic numbers
	for (int i = 0; i < atomic_numbers_vector.size(); i++) {
		std::cout << atomic_numbers_vector[i] << std::endl;
	}

	std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
  std::cout << simple_lib_function() << std::endl;
  
	return 0;
}
