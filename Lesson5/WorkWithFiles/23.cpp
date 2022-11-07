//
// Created by yaroslav_admin on 28.09.22.
//
#include <iostream>
#include <fstream>

#include <map>


int main () {
    std::map<char, int> data;
    std::string en_sogls = "BCDFGHJKLMNPQRSTVWXYZ";
    std::string en_glasnye = "AEIOUY";

    for (char a : en_sogls)
        data[a] = 0;
    std::string filename;
    std::cout << "Введите название файла для которого будет выполнен поиск самых часто встречающихся согласных:" << std::endl;
    getline(std::cin, filename);
    std::ifstream file_in(filename);
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    std::string buffer;
    char char_buffer;
    while (getline(file_in, buffer)) {
        for (unsigned int i = 0; i < buffer.length(); i++){
            char_buffer = buffer[i];
            if (std::islower(char_buffer)){
                char_buffer = std::toupper(char_buffer);
            }
            if (data.find(char_buffer) != data.end()) { // Проверка валидности ключа.
                data[char_buffer] += 1;
            }
            else {
                // Этот символ считать не нужно !
            }


        }

    }
    std::cout << "Raw data:" << std::endl;
//    for (std::map<char, int> :: iterator iterator = data.begin(); iterator != data.end(); iterator++) {
//        std::cout << iterator->first << " : " << iterator->second << std::endl;
//    }

    char max_char_key;
    int max_char_count = -1;

    for (std::map<char, int> :: iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        // std::cout << iterator->first << " : " << iterator->second << std::endl;
        if (iterator->second > max_char_count){
            max_char_count = iterator->second;
            max_char_key = iterator->first;
        }
    }

    if (max_char_count < 1)
    {
        std::cout << "Похоже в файле нет согласных" << std::endl;
        return 0;
    }

    int targets_count = 0;
    std::string target_sogls = "";
    for (std::map<char, int> :: iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        if (iterator->second == max_char_count){
            targets_count += 1;
            target_sogls += iterator->first;
            target_sogls += ' ';
        }
    }
    if (targets_count == 1)
        std::cout << "Самый часто встречающийся согласный: " << max_char_key <<". Он встретился " << max_char_count << " раз(а)." << std::endl;
    else
        std::cout << "Самые часто встречающиеся согласные: " << target_sogls <<". Они встретились " << max_char_count << " раз(а)." << std::endl;



    return 0;
}