//
// Created by yaroslav_admin on 03.10.22.
//

#ifndef CPP_1_COURSE_PART1_CLI_DATA_READER_HPP
#define CPP_1_COURSE_PART1_CLI_DATA_READER_HPP

#include <iostream>
#include <string>


float get_float_from_user(){
    float result;
    std::string buffer;
    getline(std::cin, buffer);
    while(sscanf(buffer.c_str(), "%f", &result) != 1){
        std::cout << "Не корректный ввод! Должно быть дробное или целое число, например 1.23 !" << std::endl;
        getline(std::cin, buffer);
    }
    return result;
}


bool get_bool_from_user(){
    std::string buffer;
    getline(std::cin, buffer);
    for (unsigned int i = 0; i < buffer.size(); i++){
        buffer[i] = toupper(buffer[i]);
    }
    if (buffer == "Y" or buffer == "YES" or buffer == "TRUE" or buffer == "OK" or buffer == "+")
        return true;
    if (buffer == "N" or buffer == "NO" or buffer == "FALSE" or buffer == "-")
        return false;
    std::cout << "Не корректный ввод! y/n :" << std::endl;
    return get_bool_from_user();
}

int get_int_more_0_from_user(){
    int result;
    std::string buffer;
    getline(std::cin, buffer);
    while(sscanf(buffer.c_str(), "%d", &result) != 1 or result <= 0){
        std::cout << "Не корректный ввод! Должно быть целое число > 0, например 16 !" << std::endl;
        std::cout << "Введите число :";

        getline(std::cin, buffer);
    }
    return result;
}

int get_any_int_from_user(){
    int result;
    std::string buffer;
    getline(std::cin, buffer);
    while(sscanf(buffer.c_str(), "%d", &result) != 1){
        std::cout << "Не корректный ввод! Должно быть целое число, например 10 !" << std::endl;
        std::cout << "Введите число :";

        getline(std::cin, buffer);
    }
    return result;
}

#endif //CPP_1_COURSE_PART1_CLI_DATA_READER_HPP
