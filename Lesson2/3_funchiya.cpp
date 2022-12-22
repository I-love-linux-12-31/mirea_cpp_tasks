//lesson 2

#include <iostream>
#include <cmath>


double func (double x, double y, double b) {
    return log(b - y) * sqrt(b - x);
}

int main() {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    double x, y, b;
    std::cout << "Введите x :";
    std::cin >> x;
    std::cout << "Введите y :";
    std::cin >> y;
    std::cout << "Введите b :";
    std::cin >> b;
    if (x > b or y >= b){
        std::cout << "Нельзя вычислить z !" << std::endl;
        exit(0);
    }
    std::cout << "Ответ z = " << func(x, y, b) << std::endl;

    return 0;
}

