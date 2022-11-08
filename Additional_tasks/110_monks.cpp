//
// Created by yaroslav_admin on 02.11.22.
//

#include <iostream>
#include <map>
#include <vector>

//#include <>

std::map<u_int, u_int[3]> monks;

// if (stats.find(i) != stats.end()) { // Проверка валидности ключа.

bool is_delimiter(char c){
    for (char i : " \t\n")
        if (c == i)
            return true;
    return false;
}

std::vector<u_int> split(std::string &str){
    std::vector<u_int> result;
    std::string buffer;
    int int_buffer;
    for(char i : str){
        if (!is_delimiter(i)){
            buffer += i;
        }
        else {
            if (!buffer.empty())
                sscanf(buffer.c_str(), "%d", &int_buffer);
                result.push_back((u_int)int_buffer);
            buffer.clear();
        }
    }
    if (!buffer.empty()) {
        //result.push_back(buffer);
        sscanf(buffer.c_str(), "%d", &int_buffer);
        result.push_back((u_int)int_buffer);
    }
    return result;
}










int main(){
    int n = 0;
    std::cout << "Сколько строк с информацией о монахах вы хотите ввести?" << std::endl;
    std::cin >> n;

    std::string buffer;
    getline(std::cin, buffer); // bugfix
    for (u_int i = 0; i < n; i++){
        std::cout << "$ ";
        getline(std::cin, buffer);
        if (buffer.empty()){
            n += 1;
            std::cout << "Bad input !!!\n";
        }
//        std::cout << "==============" << std::endl;
//        for (u_int str : split(buffer)){
//            std::cout << ">>" << str << std::endl;
//        }
        auto current_monk_data = split(buffer);
        monks[current_monk_data[0]][0] = current_monk_data[1];
        monks[current_monk_data[0]][1] = current_monk_data[2];
        monks[current_monk_data[0]][2] = current_monk_data[3];
    }


    std::cout << "==============" << std::endl;
    for (std::map<u_int, u_int[3]> :: iterator iterator = monks.begin(); iterator != monks.end(); iterator++) {
        std::cout << iterator->first << " : " << iterator->second[0] << " " << iterator->second[1] << " " << iterator->second[2] << std::endl;
    }
    std::cout << "==============" << std::endl;
    std::cout << "Доступные команды 1, 2:" << std::endl;
    getline(std::cin, buffer);
    if (buffer.empty()){
        std::cout << "Bad input !!!\n";
    }
    std::cout << " You chose : " << buffer << std::endl;
    auto command_data = split(buffer);
    switch (command_data[0]){
        case 1:

            break;
        case 2:
            break;
        default:
            std::cout << "Неизвестная команда\n";
            return -1;
    }
    return 0;
}