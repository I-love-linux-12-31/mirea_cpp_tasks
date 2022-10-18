//lesson 4

#include <iostream>
#include <cmath>


double get_triangle_s (double a, double b, double c) {
    double p = (a + b + c) / 2;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}
double get_circle_s (double r) {
    return 3.14 * pow(r, 2);
}
double get_box_s (double a, double b) {
    return a * b;
}


bool is_triangle (double a, double b, double c) {
    if ((a < (b+c)) and (b < (a+c)) and (c < (a+b)))
        return true;
    return false;
}


double read_data () {
    double temp;
    std::cin >> temp;
    while (temp <= 0.0){
        std::cout << "Должно быть > 0. Введите новое: ";
        std::cin >> temp;
    }
    return temp;
}

int get_mode () {
    int temp;
    std::cout << "\033[32m\033[1m ->\033[0m";
    std::cin >> temp;
    while (temp < 0 or temp > 2 ){
        std::cout << "Должно быть 0, 1 или 2. Введите новое: ";
        std::cin >> temp;
    }
    return temp;
}

int main() {
    double a, b, c, h, r;
    std::cout << "Площадь чего вы хотите посчитать?" << std::endl;
    std::cout << "0) Треугольника." << std::endl;
    std::cout << "1) Прямоугольника." << std::endl;
    std::cout << "2) Круга." << std::endl;
    switch (get_mode()) {
        case 0:
            std::cout << "== Треугольник ==" << std::endl;
            std::cout << "Введите сторонуc a: ";
            a = read_data();
            std::cout << "Введите сторонуc b: ";
            b = read_data();
            std::cout << "Введите сторонуc c: ";
            c = read_data();
            //h = read_data();
            if (is_triangle(a, b, c)) {
                std::cout << "S = " << get_triangle_s(a, b, c) << std::endl;
                break;
            }
            std::cout << "\033[31mТреугольник с такими сторонами существовать не может !\033[0m" << std::endl;
            break;
        case 1:
            std::cout << "== Прямоугольник ==" << std::endl;
            std::cout << "Введите сторону a: ";
            //std::cin >> a;
            a = read_data();
            std::cout << "Введите сторону b: ";
            //std::cin >> b;
            b = read_data();
            std::cout << "S = " << get_box_s(a, b) << std::endl;
            break;
        case 2:
            std::cout << "== Круг ==" << std::endl;
            std::cout << "Введите радиус: ";
            //std::cin >> r;
            r = read_data();
            std::cout << "S = " << get_circle_s(r) << std::endl;
            break;
    }

    return 0;
}

