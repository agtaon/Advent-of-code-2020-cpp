#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){

    std::fstream boarding_passes;
    std::string boarding_pass;

    int maximum_prod = 0;

    boarding_passes.open("C:/Users/agfrxa/Python/advent of code 2020/day5/input.txt", std::ios::in);
    while (std::getline(boarding_passes, boarding_pass)){

        int row [2] = {0, 127};
        int col [2] = {0, 7};

        for (int i = 0; i < boarding_pass.size(); i++) {

            if (boarding_pass[i] == 'F') {
                row[1] -= (row[1] - row[0] + 1) / 2;
            }

            if (boarding_pass[i] == 'B') {
                row[0] += (row[1] - row[0] + 1) / 2;
            }

            if (boarding_pass[i] == 'L') {
                col[1] -= (col[1] - col[0] + 1) / 2;
            }

            if (boarding_pass[i] == 'R') {
                col[1] += (col[1] - col[0] + 1) / 2;
            }

        }
        if (row[0] * 8 + col[0] > maximum_prod) {
            maximum_prod = row[0] * 8 + col[0];
        }

    }

    boarding_passes.close();
    std::cout << maximum_prod;
}
