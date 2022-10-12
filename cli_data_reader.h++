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
//    for (char a : buffer){
//        a = toupper(a);
//    }
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

#endif //CPP_1_COURSE_PART1_CLI_DATA_READER_HPP
