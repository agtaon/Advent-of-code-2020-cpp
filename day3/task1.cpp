#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string str;
    int len_row = 31;
    int no_of_steps = 3;
    int current_index = 0;
    int no_of_encounters = 0;
    while (std::getline(std::cin, str)) {
            if (str[current_index] == '#') {
                no_of_encounters++;
            }
            current_index = (current_index + no_of_steps) % len_row;


    }

    std::cout << no_of_encounters;

}
