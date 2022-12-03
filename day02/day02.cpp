#include <fstream>
#include <iostream>
#include <map>
#include <tuple>

using std::string;
using std::tuple;
using std::map;

int main(int n_args, char* args[]) {
    if (n_args != 2) {
        std::cout << "Error: please pass the input file!" << std::endl;
        return -1;
    }

    map<tuple<char, char>, int> outcomes1 = {
        {{ 'A', 'X' }, 3},
        {{ 'A', 'Y' }, 6},
        {{ 'A', 'Z' }, 0},
        {{ 'B', 'X' }, 0},
        {{ 'B', 'Y' }, 3},
        {{ 'B', 'Z' }, 6},
        {{ 'C', 'X' }, 6},
        {{ 'C', 'Y' }, 0},
        {{ 'C', 'Z' }, 3}
    };

    map<tuple<char, char>, char> outcomes2 = {
        {{ 'A', 'X' }, 'Z' },
        {{ 'A', 'Y' }, 'X' },
        {{ 'A', 'Z' }, 'Y' },
        {{ 'B', 'X' }, 'X' },
        {{ 'B', 'Y' }, 'Y' },
        {{ 'B', 'Z' }, 'Z' },
        {{ 'C', 'X' }, 'Y' },
        {{ 'C', 'Y' }, 'Z' },
        {{ 'C', 'Z' }, 'X' }
    };

    map<char, int> your_draw = {
        { 'X', 1 },
        { 'Y', 2 },
        { 'Z', 3 }
    };

    map<char, int> outcome_score = {
        { 'X', 0 },
        { 'Y', 3 },
        { 'Z', 6 }
    };

    std::ifstream file(args[1]);
    string line;
    int score1 = 0;
    int score2 = 0;

    while (std::getline(file, line)) {
        score1 += outcomes1[{line[0], line[2]}];
        score1 += your_draw[line[2]];

        score2 += outcome_score[line[2]];
        score2 += your_draw[outcomes2[{line[0], line[2]}]];
    }

    std::cout << "part 1: " << score1 << std::endl;
    std::cout << "part 2: " << score2 << std::endl;
}