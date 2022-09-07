//lesson 2

#include <iostream>
#include <cmath>


double func (double x, double y, double b) {
    return log(b - y) * sqrt(b - x);
}

int main() {
    double x, y, b;
    std::cout << "Введите x :";
    std::cin >> x;
    std::cout << "Введите y :";
    std::cin >> y;
    std::cout << "Введите b :";
    std::cin >> b;
    std::cout << "Ответ w = " << func(x, y, b) << std::endl;

    return 0;
}

