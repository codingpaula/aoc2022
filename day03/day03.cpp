#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using std::string;
using std::set;
using std::set_intersection;

// 1: [........]
// 2: [........]
// 3: [........]
// 4: [ref to 1]
// 5: [ptr to 2]

// reference to a const set of chars
// reference = is always what it was created for
// pointer = pointing to something that can be changed
void print_set(const set<char> &to_be_printed) {
    for (auto it = to_be_printed.begin(); it != to_be_printed.end(); ++it)
        std::cout << *it; // <- de-reference operator: get object that's behind the iterator
}


int priority(char item) {
    int ascii = (int)item;
    if (ascii > 90) return ascii - 96;
    else return ascii - 38;
}

// array of char pointers
int main(int n_args, char* args[]) {
    if (n_args != 2) {
        std::cout << "Error: please pass the input file!" << std::endl;
    }

    std::ifstream file(args[1]);


    string a = "hello";
    string& reference = a; // again saves the memory address of a

    reference[0] = 'H';

    string* ptr = &a; // take pointer to a
    ptr->size();
    a.size();
    reference.size();
    // --> the same!

    string b = *ptr; // take content of ptr and create new variable
    b[0] = 'X'; // <-- does not change a!

    // DOES change a:
    (*ptr)[0] = 'X';
    string& c = *ptr;
    c[0] = 'X';

    string** ptrptr = &ptr;
    string*& ptrref = ptr;



    string line;
    int score = 0;
    while (std::getline(file, line)) {
        int splitlength = line.length()/2;
        std::cout << &splitlength; // not necessarily the same address every loop
        string compartment_one = line.substr(0, splitlength);
        string compartment_two = line.substr(splitlength, line.length());

        // std::cout << compartment_one << " <- one ";
        // std::cout << compartment_two << " <- two ";

        set<char> set_comp_one;
        for (auto i : compartment_one)
            set_comp_one.insert(i);

        set<char> set_comp_two;
        for (auto i : compartment_two)
            set_comp_two.insert(i);

        print_set(set_comp_one); // <- reference to set
        // &set_comp_one <- gets the pointer to the set
        // std::cout << " - ";
        // print_set(&set_comp_two);

        // std::cout << " - ";

        set<char> common;
        set_intersection(
            set_comp_one.begin(),
            set_comp_one.end(),
            set_comp_two.begin(),
            set_comp_two.end(),
            std::inserter(common, common.begin()));

        // std::cout << ": ";

        // print_set(&common);
        char result = *common.begin();
        for (auto it = common.begin(); it != common.end(); ++it) {
            result = *it;
        }
        // std::cout << " <- common" << std::endl;
        score += priority(result);
    }

    std::cout << "part 1: " << score << std::endl;
    std::cout << "part 2: " << std::endl;
}