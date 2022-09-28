//
// Created by yaroslav_admin on 28.09.22.
//
#include <random>
#include <iostream>
#include <time.h>


int get_random(){
    std::srand(time(NULL));
    int value = std::rand();
    // std::cout << value << std::endl;
    if (value > 10000){
        value %= 10000;
    }
    if (value < 1025){
        value += 1024;
    }
    return value;


}


bool check_correct(int &value){
    std::string temp = std::to_string(value);
    for (unsigned int i = 0; i < 4; i++){
        for (unsigned int j = 0; j < 4; j++){
            if (i == j){
                continue;
            }
            if (temp[i] == temp[j]){
                return false;
            }
        }
    }
    return true;
}


int get_correct_random(){
    int value = 1000;
    while (!check_correct(value)){
        value = get_random();
    }
    return value;
}

int get_correct_int_from_user(){
    int result = -1;
    std::string str_buffer;
    std::cout << "Введите число: ";
    std::cin >> str_buffer;
    while (sscanf(str_buffer.c_str(), "%d", &result) != 1 or result <= 999 or result >= 10000){
        std::cout << "\033[31mВвод некорекиен!\033[0m Введите число из интервала [1000, 9999]: ";
        std::cin >> str_buffer;
    }
    return result;
}

int main(){
    int value = get_correct_random();
    std::cout << value << std::endl;
    std::string str_value = std::to_string(value);
    int int_buff = 0;

    int pluses = 0;
    int minuses = 0;
    bool winner = false;
    while (!winner){
        pluses = 0;
        minuses = 0;
        int_buff = get_correct_int_from_user();
        // std::cout << "got :" << int_buff << std::endl;
        std::string buffer = std::to_string(int_buff);
        if (buffer == str_value){
            std::cout << "\033[93m\033[1mВы выиграли !\033[0m" << std::endl;
            return 0;
        }
        for (int i = 0 ; i < 4; i++){
            if (buffer[i] == str_value[i]){
                pluses += 1;
            }
            else{
                for (int j = 0 ; j < 4; j++){
                    if (str_value[j] == buffer[i]){
                        minuses += 1;
                        break;
                    }
                }
            }
        }
        std::cout << "+ : " << pluses << std::endl;
        std::cout << "- : " << minuses << std::endl;


    }

    return 0;
}
