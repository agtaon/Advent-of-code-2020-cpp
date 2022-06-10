#include <iostream>
#include <vector>
#include <string>



int main() {
    std::string str;
    int len_row = 31;
    int no_of_steps1 = 1;
    int no_of_steps2 = 3;
    int no_of_steps3 = 5;
    int no_of_steps4 = 7;
    int no_of_steps5 = 1;
    int current_index1 = 0;
    int current_index2 = 0;
    int current_index3 = 0;
    int current_index4 = 0;
    int current_index5 = 0;
    int current_row = 0;
    int no_of_encounters1 = 0;
    int no_of_encounters2 = 0;
    int no_of_encounters3 = 0;
    int no_of_encounters4 = 0;
    int no_of_encounters5 = 0;
    while (std::getline(std::cin, str)) {
            if (str[current_index1] == '#') {
                no_of_encounters1++;
            }
            if (str[current_index2] == '#') {
                no_of_encounters2++;
            }
            if (str[current_index3] == '#') {
                no_of_encounters3++;
            }
            if (str[current_index4] == '#') {
                no_of_encounters4++;
            }
            if ((str[current_index5] == '#') && current_row % 2 == 0) {
                no_of_encounters5++;
            }
            current_row++;
            if (current_row % 2 == 0) {
                current_index5 = (current_index5 + no_of_steps5) % len_row;
            }
            current_index1 = (current_index1 + no_of_steps1) % len_row;
            current_index2 = (current_index2 + no_of_steps2) % len_row;
            current_index3 = (current_index3 + no_of_steps3) % len_row;
            current_index4 = (current_index4 + no_of_steps4) % len_row;

    }

    std::cout << no_of_encounters1*no_of_encounters2*no_of_encounters3*no_of_encounters4*no_of_encounters5;


}
