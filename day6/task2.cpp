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

    std::vector<char> answers;
    std::vector<char> unique_list;

    while (std::getline(group_answers, answer)){
        for (int i=0; i<answer.size(); i++){
            answers.push_back(answer[i]);


        }
        if (answer.empty()){
            unique_list.push_back(answers[0]);
            number_of_answers ++;
            for (int j=0; j<answers.size(); j++){
                if (std::all_of(unique_list.begin(), unique_list.end(), [answers, j](char y) { return answers[j] != y; })){
//                    std::cout << answers[j];
                    unique_list.push_back(answers[j]);
                    number_of_answers ++;
                    }
            }
            for (int k=0; k<unique_list.size(); k++){
//                std::cout << unique_list[k];
            }
//            std::cout << "-";
            answers.clear();
            unique_list.clear();
        }
    }
    group_answers.close();

std::cout << number_of_answers;


}
