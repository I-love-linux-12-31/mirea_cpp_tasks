//lesson 2

#include <iostream>


int main() {
    int n;
    std::cout << "Введите N :";
    std::cin >> n;
    if (n < 1) {
        n = 1;
    }
    for (int i = 0; i < 10; i++){
        std::cout << n + i << std::endl;
    }

    return 0;
}

