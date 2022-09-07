//lesson 3

#include <iostream>
#include <cmath>

double get_m(double s, double p, double n) {
    double r = p / 100;
    return (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}


int main() {
    double s, p, n;
    //S, p, n
    std::cout << "Введите s :" << std::endl;
    std::cin >> s;
    std::cout << "Введите p :" << std::endl;
    std::cin >> p;
    std::cout << "Введите n :" << std::endl;
    std::cin >> n;



    std::cout << "m = ";
    std::cout << get_m(s, p, n) << std::endl;

    return 0;
}

