//
// Created by yaroslav_admin on 12.11.22.
//
// Задача 1. Спиннеры
#include <iostream>


int main(){
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    int n = (c - a) / b;
    std::cout << n << std::endl;
    return 0;
}