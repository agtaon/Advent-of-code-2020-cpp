#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main(){
    std::fstream instruction_stream;
    std::string instruction;
    std::vector<std::string> instructions;
    std::string temp_instruction;
    int current_index = 0;
    int current_value = 0;
    int iter = 0;


    instruction_stream.open("C:/Users/agfrxa/Python/advent of code 2020/day8/input.txt", std::ios::in);
//    rules.open("D:/Python/Advent-of-code-2020-python/day7/input.txt", std::ios::in);
    while (std::getline(instruction_stream, instruction)){
        instructions.push_back(instruction);
    }
    while (instructions[current_index] != "used"){
        iter ++;
        if ( iter > 10000 ){
            break;
        }
        temp_instruction = instructions[current_index];
        instructions[current_index] = "used";
        if ( temp_instruction.substr(0, 3) == "jmp" ){
            if ( temp_instruction.substr(4, 1) == "+" ){
                current_index += std::stoi(temp_instruction.substr(5, std::string::npos));
            }
            else{
                current_index -= std::stoi(temp_instruction.substr(5, std::string::npos));
            }
        }

        else if ( temp_instruction.substr(0, 3) == "acc" ){
            current_index ++;
            if ( temp_instruction.substr(4, 1) == "+" ){
                current_value += std::stoi(temp_instruction.substr(5, std::string::npos));
            }
            else{
                current_value -= std::stoi(temp_instruction.substr(5, std::string::npos));
            }
        }
        else {
            current_index ++;
        }


    }
    std::cout << current_value;
}
