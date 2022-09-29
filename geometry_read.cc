#include <iostream>
#include <fstream>
#include <string>

int main () {
    std::string line;
    ifstream myfile ("h2o.inp");
    if (myfile.is_open()) {
        while (getline (myfile, line) ) {
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return 0;
}
