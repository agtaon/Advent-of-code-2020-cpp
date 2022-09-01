#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

std::vector<std::string> split(const std::string &str, char delim){
    std::vector<std::string> result;
    std::stringstream ss (str);
    std::string temp_str;

    while (std::getline (ss, temp_str, delim)) {
        result.push_back(temp_str);
    }

    return result;
}


std::vector<std::string> map_builder (std::vector<std::string> &split_rule){
    std::vector<std::string> result;
    std::string numbers = "0123456789";
    for (int i=0; i<split_rule.size(); i++) {
        if ( numbers.find((split_rule[i])) != std::string::npos ) {
            result.push_back(split_rule[i] + "_" + split_rule[i+1] + "_" + split_rule[i+2]);
        }
    }
    return result;
}

int bag_tree(std::map<std::string, std::vector<std::string>> &bag_map, std::string &bag, int mother_bags, int tot_bags){
    std::vector<std::string> contents = bag_map[bag];
    for (int i=0; i < contents.size(); i++){
        std::string inp_bag = contents[i].substr(2,std::string::npos);
        tot_bags += mother_bags * (contents[i][0] - '0');   // - '0' because char type digits are encoded in order from 48 (for '0' in most encodings) -> 57 (for '9'). int 0 is encoded to 0
        int temp_mother_bags = mother_bags * (contents[i][0] - '0');
        tot_bags = bag_tree(bag_map, inp_bag, temp_mother_bags, tot_bags);
    }

    return tot_bags;
}

int main(){
    std::fstream rules;
    std::string rule;
    std::map<std::string, std::vector<std::string>> bag_map;
    std::string bag;
    std::vector<std::string> vec_rule;
    std::vector<std::string> values;
    char delimeter = ' ';
    std::string golden_bag = "shiny_gold";

    int counter = 0;
    rules.open("C:/Users/agfrxa/Python/advent of code 2020/day7/input.txt", std::ios::in);
//    rules.open("D:/Python/Advent-of-code-2020-python/day7/input.txt", std::ios::in);
    while (std::getline(rules, rule)){
        vec_rule = split(rule, delimeter);
        bag = vec_rule[0] + "_" + vec_rule[1];
        values = map_builder(vec_rule);
        for (int i=0; i<values.size(); i++){
            bag_map[bag].push_back(values[i]);
        }
    }

    counter = bag_tree(bag_map, golden_bag, 1, 0);

    rules.close();
    std::cout << counter;
}
