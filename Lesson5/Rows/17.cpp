//
// Created by yaroslav_admin on 26.10.22.
//
#include "../../cli_data_reader.h++"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

double round_6(double val){
    return round(val * 1000000) / 1000000 ;
}

long int factorial (long int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}

int main() {
    std::cout << "Введите X:" << std::endl;
    double x = get_float_from_user();
    double result, delta;

    int done_pr = 0;
    // Макс значащее k : N (Значения остальных элементов является машинным нулём !!!)
    const long int N = 36; // Получено экспериментальным путём. (Подстановкой карайних значений)
    for (long int k = 0; k < N; k++){
        // Отображение процентов !
//        if (k % (N / 100) == 0){
//            done_pr += 1;
//            std::cout << "Done " << done_pr << "%, last delta = " << delta<< " result now = " << result << std::endl;
//        }
        // Приоброзавание выражения :
        // delta = ((double)factorial(k + 2)) / (pow((int)k + 1, 2) * pow(x, 2.0 * (double)k + 2.0));
        // delta = (((double)factorial(k)) * (k + 2)) / (pow((int)k + 1, 2) * pow(x, 2.0 * (double)k + 2.0));
        delta = (((double)factorial(k)) * (double)(k + 2)) / ((int)k + 1 * pow(x, 2.0 * (double)k + 2.0));
//        if (delta != 0.0)
//            std::cout << delta << std::endl;
        result += delta;
    }

    std::cout << "Результат с точностью 10^(-6) : " << round_6(result) << std::endl;
    // 0.000122081
    // rounded: 0.000122

}