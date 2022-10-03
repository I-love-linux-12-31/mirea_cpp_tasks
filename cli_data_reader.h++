//
// Created by yaroslav_admin on 03.10.22.
//

#ifndef CPP_1_COURSE_PART1_CLI_DATA_READER_HPP
#define CPP_1_COURSE_PART1_CLI_DATA_READER_HPP

#include <iostream>


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

#endif //CPP_1_COURSE_PART1_CLI_DATA_READER_HPP
