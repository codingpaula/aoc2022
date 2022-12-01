#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::vector;
using std::string;

int main(int n_args, char* args[]) {
    if (n_args != 2) {
        std::cout << "Error: please pass the input file!" << std::endl;
        return -1;
    }

    // ifstream = input file stream
    std::ifstream file(args[1]);

    vector<int> data = {0};

    string line;
    // file.rdbuf = read buffer
    while (std::getline(file, line)) {
        if (line != "") {
            data.back() += std::stoi(line);
            // stoi = string to integer
        } else {
            data.push_back(0);
        }
    }

    std::sort(data.begin(), data.end());
    std::cout << "part 1: " << data.back() << std::endl;
    
    int sum_of_three_highest = std::accumulate(data.end()-3, data.end(), 0);
    std::cout << "part 2: " << sum_of_three_highest << std::endl;
}