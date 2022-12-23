//
// Created by yaroslav_admin on 09.11.22.
//

#include <iostream>
#include "../../cli_data_reader.h++"

bool is_prime(int a) {
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

bool isSofiZermen (int num){
    if (!is_prime(num) or !is_prime(2*num + 1))
        return false;
    return true;
}

int main(){
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    std::cout << "Данная программа ищет числа Софи Жермен в диапозоне [m, n]" << std::endl;
    int m, n;
    std::cout << "Введите число m:";
    m = get_int_more_0_from_user();
    std::cout << "Введите число n:";
    n = get_int_more_0_from_user();
    std::cout << "Числа Софи Жермен в диапозоне [m, n]:";
    for (int i = m; i < n + 1; i++)
        if (isSofiZermen(i))
            std::cout << " " << i;
    std::cout << std::endl;
}