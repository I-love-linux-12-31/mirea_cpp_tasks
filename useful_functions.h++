//
// Created by yaroslav_admin on 27.09.22.
//

#ifndef CPP_1_COURSE_PART1_USEFUL_FUNCTIONS_HPP
#define CPP_1_COURSE_PART1_USEFUL_FUNCTIONS_HPP


#include <string>
#include <cmath>

std::string get_formatted_double_middle(double &value){
    std::string result = "";
    std::string buffer;
    if (value >= 0){
        result += ' ';
    }

    double rounded = (double )((int)std::round(value * 10000)) / 10000;
    buffer  = std::to_string(rounded);
    bool after_point = false;
    unsigned short int j = 0;
    for (unsigned int i = 0; i < buffer.length(); i++){
        if (after_point){
            if (j < 4){
                result += buffer[i];
                j++;
            }
            else {
                return result;
            }
        }
        else {
            result += buffer[i];
        }

        if (buffer[i] == '.'){
            after_point = true;
        }

    }
    return result;
}

std::string get_formatted_double_short(double &value){
    std::string result = "";
    std::string buffer;
    if (value >= 0){
        result += ' ';
    }
    double rounded = (double )((int)std::round(value * 10)) / 10;

    buffer  = std::to_string(rounded);
    bool after_point = false;
    unsigned short int j = 0;
    for (unsigned int i = 0; i < buffer.length(); i++){
        if (after_point){
            if (j < 1){
                result += buffer[i];
                j++;
            }
            else {
                return result;
            }
        }
        else {
            result += buffer[i];
        }

        if (buffer[i] == '.'){
            after_point = true;
        }

    }
    return result;
}





#endif //CPP_1_COURSE_PART1_USEFUL_FUNCTIONS_HPP
