//lesson 2

#include <iostream>
#include <cmath>

#include "../useful_functions.h++"

double func(double x){
    return (pow(x, 2) - (2 * x) + 2) / (x - 1);
}

int main() {
    double j = -4;
    std::cout << "   x\t\ty\033[32m" << std::endl;

    while (j <= 4.0){
        if (j != 1) {

            double val = func(j);
            std::cout << get_formatted_double_short(j) << "    " << get_formatted_double_middle(val) << std::endl;
        }
        else {
            std::cout << get_formatted_double_short(j);
            std::cout << "    " << "\033[31mНе существует !\033[32m" << std::endl;
        }
        j = j + 0.5;
    }

    return 0;
}
