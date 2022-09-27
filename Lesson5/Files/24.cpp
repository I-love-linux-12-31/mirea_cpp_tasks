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

    for (unsigned int i = 0 ; i < en_sogls.length() ; i++){
        data[en_sogls[i]] = 1;
    }

    std::ifstream file_in("text_A");
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    std::string buffer;
    char char_buffer;
    while (file_in) {
        getline(file_in, buffer);
        for (unsigned int i = 0; i < buffer.length(); i++){
            char_buffer = buffer[i];
            if (std::islower(char_buffer)){
                char_buffer = std::toupper(char_buffer);
            }
            if (data.find(char_buffer) != data.end()) { // Проверка валидности ключа.
                //std::cout << "adding for " << char_buffer << std::endl;
                data[char_buffer] += 1;
            }
            else {
                //std::cout << "Create for " << char_buffer << std::endl;
                //data[char_buffer] = 1;
                // Этот символ считать не нужно !
            }


        }

    }

    char min_char_key;
    int min_char_count = 99999999;
    for (std::map<char, int> :: iterator iterator = data.begin(); iterator != data.end(); iterator++) {
        // std::cout << iterator->first << " : " << iterator->second << std::endl;
        if (iterator->second < min_char_count){
            min_char_count = iterator->second;
            min_char_key = iterator->first;
        }
    }
    std::cout << "Самый редко встречающийся согласный: " << min_char_key <<". Он встретился " << min_char_count << " раз(а)." << std::endl;



    return 0;
}