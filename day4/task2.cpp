#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <typeinfo>
#include <algorithm>


std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (std::getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


int main() {
    std::string str;
    std::vector<std::string> requirements = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}; // removed cid
    std::vector<std::string> split_inp;
    std::map <std::string, std::string> dict;
    std::vector<std::string> temp_split;
    std::vector<std::string> eye_colors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    std::string cm = "cm";
    std::string inches = "in";
    int num_fields;
    int found_requirements = 0;
    int bonus_requirements = 0;
    int valid_passports = 0;
    int size_str = 0;

    std::string temp_str;
    while (std::getline(std::cin, str)) {
        for (int i=0; i<7; i++) {
            if (str.find(requirements[i]) != std::string::npos) {
                found_requirements++;
                }
            }


            temp_str.append(str);
            temp_str.append(" ");

        if (found_requirements == 7) {
            temp_str.pop_back();
            split_inp = split(temp_str, ' ');
            num_fields = split_inp.size();

            for (int i=0; i<num_fields; i++) {
                temp_split = split(split_inp[i], ':');

                dict[temp_split[0]] = temp_split[1];
            }

            if ((1919 < std::stoi(dict["byr"])) && (std::stoi(dict["byr"]) < 2003)) {
                bonus_requirements++;
            }

            if ((2009 < std::stoi(dict["iyr"])) && (std::stoi(dict["iyr"]) < 2021) ) {
                bonus_requirements++;
            }

            if ((2019 < std::stoi(dict["eyr"]) && (std::stoi(dict["eyr"]) < 2031))) {
                bonus_requirements++;
            }


            if (std::stoi(dict["hgt"])) {
                if (dict["hgt"].rfind(cm) != std::string::npos) {
                    if (149 < (std::stoi(dict["hgt"])) && (std::stoi(dict["hgt"]) < 194)) {
                        bonus_requirements++;
                    }
                }
                if (dict["hgt"].rfind(inches) !=  std::string::npos) {
                    if (58 < (std::stoi(dict["hgt"])) && (std::stoi(dict["hgt"]) < 77)) {
                        bonus_requirements++;
                    }
                }
            }

            if ((dict["hcl"].at(0)=='#') && (dict["hcl"].find_first_not_of("#0123456789abcdef") == std::string::npos)&& (dict["hcl"].length() == 7)) {
                bonus_requirements++;
            }


            if (std::find(std::begin(eye_colors), std::end(eye_colors), dict["ecl"]) != std::end(eye_colors)) {
                bonus_requirements++;
            }


            if ((dict["pid"].length() == 9) && (dict["pid"].find_first_not_of("0123456789") == std::string::npos)) {
                bonus_requirements++;
            }

        }

        if ((str == "") || (found_requirements == 7)) {
                if (bonus_requirements == 7) {
                    valid_passports++;
                }
                found_requirements = 0;
                bonus_requirements = 0;
                temp_str.clear();
                dict.clear();
            }
    }
    std::cout << valid_passports;
}
