//lesson 2

#include <iostream>
#include <cmath>

double func(double x){
    return (pow(x, 2) - (2 * x) + 2) / (x - 1);
}

int main() {
    double j = -4;
    std::cout << "x\t\ty" << std::endl;

    while (j <= 4.0){
        if (j != 1) {
            std::cout << j << "\t\t" << func(j) << std::endl;
        }
        else {
            std::cout << j << "\t\t" << "Не существует !" << std::endl;
        }
        j = j + 0.5;
    }

    return 0;
}

