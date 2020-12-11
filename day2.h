//
// Created by micha on 11.12.2020.
//
#pragma once

#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

class day2 {
public:
    day2() {
        run();
    }

    void get_items(std::string i_string, int *min, int *max, char *to_search, int *end_of_prefix) {
        auto minus = i_string.find('-');
        auto div = i_string.find(':');
        *min = std::stoi(i_string.substr(0, minus));
        *max = std::stoi(i_string.substr(minus + 1, div - 4));
        *to_search = i_string[div - 1];
        *end_of_prefix = div;
    }

    void run() {
        std::ifstream file("inputs/day2_input.txt");
        int okay_passwords = 0;
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                int min;
                int max;
                char char_to_find;
                int end_of_prefix;
                int count = 0;
                get_items(line, &min, &max, &char_to_find, &end_of_prefix);
                for (auto x = end_of_prefix; x < line.size(); x++) {
                    if (line[x] == char_to_find) {
                        count++;
                        if (count > max)
                            break;
                    }
                }
                if (count >= min && count <= max)
                    okay_passwords++;
            }
            std::cout << "there are " << okay_passwords << " okay passwords!" << std::endl;
            file.close();
        }
    }

};


