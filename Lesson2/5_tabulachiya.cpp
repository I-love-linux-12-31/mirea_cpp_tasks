//lesson 2

#include <iostream>
#include <cmath>
#include <iomanip>

double func(double x){
    return (pow(x, 2) - (2 * x) + 2) / (x - 1);
}

int main() {
    double j = -4;
    std::cout << "   x\t\ty\033[32m" << std::endl;

    while (j <= 4.0){
        if (j != 1) {
            //std::cout << std::setprecision(3) << std::setiosflags(std::ios::left) << std::setw(5) <<  std::setfill('0') << (float)j << "\t\t" << func(j) << std::endl;
            printf("%10f    %f\n", j, func(j));
        }
        else {
            printf("%10f", j);
            std::cout << "    " << "\033[31mНе существует !\033[32m" << std::endl;
        }
        j = j + 0.5;
    }

    return 0;
}

