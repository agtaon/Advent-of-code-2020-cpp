#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main(){

    std::fstream boarding_passes;
    std::string boarding_pass;
    std::vector<int> seat_id_list;


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
                col[0] += (col[1] - col[0] + 1) / 2;
            }

        }
        seat_id_list.push_back(row[0] * 8 + col[0]);
    }

    boarding_passes.close();

    std::sort (seat_id_list.begin(), seat_id_list.end());

    for (int i = 0; i < seat_id_list.size() - 1; i++){
            if (seat_id_list[i] != seat_id_list[i+1]-1){
                std::cout << seat_id_list[i] << ' ' << seat_id_list[i+1];
            }
        }
}
