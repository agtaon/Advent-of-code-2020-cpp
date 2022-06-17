#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>



int main(){
    std::fstream group_answers;
    std::string answer;
    int number_of_answers = 0;
    group_answers.open("C:/Users/agfrxa/Python/advent of code 2020/day6/input.txt", std::ios::in);

    std::vector<std::string> answers = {};

    while (std::getline(group_answers, answer)){
        answers.push_back(answer);
        std::cout << answer << "\n";

        if (answer.empty()){
            std::cout << answers[1] << "\n";
            break;
            answers.clear();
        }

    }
    group_answers.close();

std::cout << number_of_answers;


}
