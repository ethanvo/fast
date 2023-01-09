#include <string>
#include <vector>
#include <set>

std::vector<int> get_atomic_numbers(
		const std::vector<std::string>& symbols);

std::set<int> get_unique_atomic_numbers(
		const std::vector<int>& atomic_numbers);
