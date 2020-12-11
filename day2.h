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

    bool ex_a(std::string line){
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
            return true;
        return false;
    }

    bool ex_b(std::string line){
        int min;
        int max;
        char char_to_find;
        int end_of_prefix;
        get_items(line, &min, &max, &char_to_find, &end_of_prefix);
        bool first = line[end_of_prefix+1+min]==char_to_find;
        bool second = line[end_of_prefix+1+max]==char_to_find;
        if((first+second) ==1)
            return true;
        return false;
    }


    void run() {
        std::ifstream file("inputs/day2_input.txt");
        int okay_passwords_a = 0;
        int okay_passwords_b = 0;
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                okay_passwords_a += ex_a(line);
                okay_passwords_b += ex_b(line);
            }
            file.close();
        }

        std::cout << "There are " << okay_passwords_a << " okay passwords for Ex A" <<std::endl;
        std::cout << "There are " << okay_passwords_b << " okay passwords for Ex B" <<std::endl;
    }

};


