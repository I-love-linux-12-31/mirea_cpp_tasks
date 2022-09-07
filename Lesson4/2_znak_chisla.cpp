//lesson 4

#include <iostream>
#include <cmath>

double func(double x){
    if (x > 0) {
        return 1;
    }
    else {
        if (x == 0){
            return  0;
        }
        else {
            return -1;
        }

    }
}

int main() {
    double x, result;
    std::cout << "Введите x: ";
    std::cin >> x;
    result = func(x);
    if (result == 1){
        std::cout << "+" << std::endl;
    }
    else {
        if (result == 0) {
            std::cout << "0" << std::endl;
        }
        else {
            std::cout << "-" << std::endl;
        }
    }

    return 0;
}

