#include <iostream>
#include <vector>
#include <string>


int main() {
    std::string str;
    std::vector<std::string> requirements = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}; // removed cid
    int found_requirements = 0;
    int num_valid = 0;
    int size_str = 0;
    while (std::getline(std::cin, str)) {
            if (str == "") {
                found_requirements = 0;
            }

        for (int i=0; i<7; i++) {
            if (str.find(requirements[i]) != std::string::npos) {
                found_requirements++;

                }
        }

        if (found_requirements == 7) {
            num_valid++;
            found_requirements = 0;

        }
    }
    std::cout << num_valid;
}
