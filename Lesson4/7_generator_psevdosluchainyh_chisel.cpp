
#include <iostream>

#include "../cli_data_reader.h++"

double last_s = 0;
int8_t mode = 1;
int m = 37;
int b = 3;
int c = 64;
double get_random(){
    double result;
    result = ((double )(m * last_s + b)) / (double)c;
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
    std::cout << "Вы хотите начать с больших чисел y/n :" << std::endl;
    bool user_mode_1 = get_bool_from_user();
    if (user_mode_1){
        mode = 2;
        m = 25173;
        b = 13849;
        c = 65537;
    }

    for (int i = 0; i < 16; i++) {
        std::cout << get_random() << std::endl;
    }
    return 0;
}