//
// Created by yaroslav_admin on 02.10.22.
//
// lesson 4
#include <iostream>
#include <cmath>

#include "../cli_data_reader.h++"

// a sin(b*x + c) + d

double a, b, c, d;
double func(double x){
    return a*sin(b*x + c) + d;
}

int main(){
    char output[128][16];
    std::cout << "Данная программа выводит функцию a * sin(b * x + c) + d." << std::endl;
    std::cout << "Введите a: ";
    a = (double)get_float_from_user();
    std::cout << "Введите b: ";
    b = (double)get_float_from_user();
    std::cout << "Введите c: ";
    c = (double)get_float_from_user();
    std::cout << "Введите d: ";
    d = (double)get_float_from_user() * -1.0;

    for(int y=0; y<16; y++){
        for(int x=0; x<128; x++){
            output[x][y] = ' ';
        }
    }

    double val;
    for(int x=0; x<128; x++){
        val = func(x);
        if (val < 7 and val > -7) {
            output[x][8 + (int)round(val)] = '#';
            // std::cout << "SET " << x << " " << 8 + (int)round(val) << " !" << std::endl;
        }
        else {
            // std::cout << "ERR \n";
        }
    }

    for(int y=0; y<16; y++){
        for(int x=0; x<128; x++){
            if (x == 0){
                std::cout << "\e[42m\e[1m";
            }
            std::cout << output[x][y];
            if (x == 127){
                std::cout << "\e[0m";
            }

        }
        std::cout << std::endl;
    }

}