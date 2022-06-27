#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    std::fstream group_answers;
    std::string answer;
    int number_of_answers = 0;
    std::string og_str;
    std::vector<std::string> answers = {};
    std::vector<int> vect;

//    group_answers.open("C:/Users/agfrxa/Python/advent of code 2020/day6/input.txt", std::ios::in);
    group_answers.open("D:/Python/Advent-of-code-2020-python/day6/input.txt", std::ios::in);


    while (std::getline(group_answers, answer)){
        if (answer.empty()){
            for (int i=0; i<og_str.size(); i++){
                number_of_answers += vect[i];
            }
            answers.clear();
        }


        if (answers.empty()) {
            og_str = answer;
            vect.resize(og_str.size());
            for (int i=0; i<og_str.size(); i++){
                vect[i]=1;

            }
        }
        if (!(answers.empty())){
            for (int i=0; i<og_str.size(); i++){
//                std::cout << "before" << vect[i];
                if (answer.find(og_str[i]) == std::string::npos){
                    vect[i] = 0;
                }

            }
        }
        if (!(answer.empty())){
            answers.push_back(answer);
        }
//        std::cout << answer << "\n";



    }
    group_answers.close();

std::cout << number_of_answers;


}
