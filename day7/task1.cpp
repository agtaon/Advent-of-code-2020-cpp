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
            result.push_back(split_rule[i+1] + "_" + split_rule[i+2]);
        }
    }
    return result;
}


int gold_detector (std::map<std::string, std::vector<std::string>> &bag_map, std::string &key){
    std::vector<std::string> contents = bag_map[key];
    std::string golden_bag = "shiny_gold";
    int outcome;
    if (std::find(contents.begin(), contents.end(), golden_bag) != contents.end()){
        return 1;
    }

    for (int i=0; i<contents.size(); i++){
        outcome = gold_detector(bag_map, contents[i]);
        if (outcome) {
            return outcome;
        }
    }
    return 0;
}


int main(){
    std::fstream rules;
    std::string rule;
    std::map<std::string, std::vector<std::string>> rule_set;
    std::string bag;
    std::vector<std::string> vec_rule;
    std::vector<std::string> values;
    char delimeter = ' ';


    int counter = 0;
    rules.open("C:/Users/agfrxa/Python/advent of code 2020/day7/input.txt", std::ios::in);
//    rules.open("D:/Python/Advent-of-code-2020-python/day7/input.txt", std::ios::in);
    while (std::getline(rules, rule)){
        vec_rule = split(rule, delimeter);
        bag = vec_rule[0] + "_" + vec_rule[1];
        values = map_builder(vec_rule);
        for (int i=0; i<values.size(); i++){
            rule_set[bag].push_back(values[i]);
        }
    }
    for ( const auto &key_val : rule_set ){
        std::string key = key_val.first;
        counter += gold_detector(rule_set, key);
    }
    rules.close();
    std::cout << counter;
}


