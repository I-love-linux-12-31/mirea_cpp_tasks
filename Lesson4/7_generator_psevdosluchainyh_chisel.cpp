
#include <iostream>

#include "../cli_data_reader.h++"

int last_s = 0;
int8_t mode = 1;
int m = 37;
int b = 3;
int c = 64;
int get_random(){
    double result;
    result = ((m * last_s + b)) % c;
    last_s = result;
    if (mode == 1) {
        mode = 2;
        m = 25173;
        b = 13849;
        c = 65537;
    }
    else {
        mode = 1;
        m = 37;
        b = 3;
        c = 64;
    }
    return result;
}

int main () {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    std::cout << "Вы хотите начать с больших чисел y/n :" << std::endl;
    bool user_mode_1 = get_bool_from_user();
    if (user_mode_1){
        mode = 2;
        m = 25173;
        b = 13849;
        c = 65537;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << get_random() << std::endl;
    }
    return 0;
}