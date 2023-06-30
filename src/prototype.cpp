#include <iostream>
#include <unordered_map>
#include <tuple>

// Function to create the index dictionary
std::unordered_map<std::tuple<int, int, int>, int> createIndexDict(int lmax) {
    std::unordered_map<std::tuple<int, int, int>, int> indexDict;
    int index = 0;
    for (int l = 0; l <= lmax; ++l) {
        for (int x = l; x >= 0; --x) {
            for (int y = l - x; y >= 0; --y) {
                int z = l - x - y;
                indexDict[std::make_tuple(x, y, z)] = index;
                ++index;
            }
        }
    }
    return indexDict;
}

// Function to get the index from the index dictionary
int getIndex(int lx, int ly, int lz, const std::unordered_map<std::tuple<int, int, int>, int>& indexDict) {
    auto tuple = std::make_tuple(lx, ly, lz);
    auto iter = indexDict.find(tuple);
    if (iter != indexDict.end()) {
        return iter->second;
    } else {
        return -1;
    }
}

int main() {
    int lmax = 4;
    std::unordered_map<std::tuple<int, int, int>, int> indexDict = createIndexDict(lmax);
    int tupleIndex = getIndex(2, 1, 1, indexDict);
    std::cout << tupleIndex << std::endl;
    return 0;
}

