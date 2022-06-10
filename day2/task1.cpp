#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>


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
    int valid_passwords = 0;

    std::string str;
    while (std::getline(std::cin, str)) {
        std::vector<std::string> str_array = split(str, ' ');

        std::vector<std::string> interval = split(str_array[0], '-');
        std::vector<std::string> letter = split(str_array[1], ':');
        std::string password = str_array[2];
        int num_occur = std::count (password.cbegin(), password.cend(), letter.at(0)[0]);

        if ( (std::stoi(interval[0]) <= num_occur ) && (std::stoi(interval[1]) >= num_occur) ) {
              valid_passwords++;
              }

    }

    std::cout << valid_passwords;

return 0;
}
