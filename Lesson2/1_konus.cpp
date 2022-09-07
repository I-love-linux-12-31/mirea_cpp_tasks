//lesson 2

#include <iostream>
#include <cmath>



int main() {
    double h , r1, r2;
    double l;
    double v, s;
    setlocale(LC_ALL, "ru_RU.UTF-8");

    std::cout << "Введите радиус 1 :" << std::endl;
    std::cin >> r1;

    std::cout << "Введите радиус 2 :" << std::endl;
    std::cin >> r2;
    std::cout << "Введите высоту усечённого конуса :" << std::endl;
    std::cin >> h;

    l = sqrt(pow(h, 2) + pow(r1 - r2, 2));

    v = (1.0 / 3.0) * M_2_PI * h *(pow(r1, 2) + r1 * r2 + pow(r2, 2));
    s = M_2_PI * (pow(r1, 2) + (r1 + r2) * l + pow(r2, 2));
    std::cout << "Объем :";
    std::cout << v << std::endl;
    std::cout << "Площадь полной поверхности :";
    std::cout << s << std::endl;




    return 0;
}

