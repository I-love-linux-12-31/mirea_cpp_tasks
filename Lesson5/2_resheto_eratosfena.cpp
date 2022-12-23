// Lesson 5

#include <iostream>

bool is_prime(int &a) {
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    int n;
    std::cout << "Введите число :" << std::endl;
    std::cin >> n;
    std::cout << "Простые числа :" << std::endl;

    for (int i = 2; i < n; i++){
        if (is_prime(i)){
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;

    return 0;
}