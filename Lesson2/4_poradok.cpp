//lesson 2

#include <iostream>
#include <cmath>


int main() {
    int n;
    float buff;
    std::cout << "Введите N :";
    std::cin >> buff;
    n = round(buff);
    if (n < -10){
        std::cout << "Натуральных чисел в диапозоне от n до n +10 не найдено." << std::endl;
    }
    for (int i = 0; i < 10; i++){
        if (n + i > 0) {
            std::cout << n + i << std::endl;
        }
    }

    return 0;
}

