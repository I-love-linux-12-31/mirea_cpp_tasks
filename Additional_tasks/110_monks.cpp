//
// Created by yaroslav_admin on 02.11.22.
//

#include <iostream>
#include <map>
#include <vector>

//#include <>

std::map<u_int, u_int[3]> data;

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
        std::cout << "==============" << std::endl;
        for (auto str : split(buffer)){
            std::cout << ">>" << str << std::endl;
        }
    }
    return 0;
}