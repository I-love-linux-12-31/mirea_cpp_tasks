//
// Created by yaroslav_admin on 28.09.22.
//

//lesson 3
#include <iostream>
#include <string>

// std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int get_char_level(char &a){
    for (unsigned short int i = 0; i < alphabet.length(); i++){
        if (alphabet[i] == a){
            return i * 10;
        }
        if (std::tolower(alphabet[i]) == a){
            return i * 10 + 5;
        }
    }
    return -1;
}

int main() {
    // setlocale(LC_ALL, ""); for windows
    std::cout << "\033[32m\033[1mВведите строку для обработки :\033[0m\033[1m";
    std::string my_string;
    std::cin >> my_string;
    char temp;
    int char_level_0;
    int char_level_1;
    for (int i=0;i < my_string.length() - 1; i++){
        for (int j=0;j < my_string.length() - 1; j++){
            char_level_0 = get_char_level(my_string[j]);
            char_level_1 = get_char_level(my_string[j + 1]);
            if (char_level_1 < char_level_0){
                temp = my_string[j];
                my_string[j] = my_string[j + 1];
                my_string[j + 1] = temp;
            }
        }
    }
    std::cout << my_string << std::endl;

    return 0;
}


