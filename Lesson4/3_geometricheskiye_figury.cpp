//lesson 4

#include <iostream>
#include <cmath>


double get_triangle_s (double a, double h) {
    return (a * h) / 2.0;
}
double get_circle_s (double r) {
    return 3.14 * pow(r, 2);
}
double get_box_s (double a, double b) {
    return a * b;
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

int main() {
    double a, b, h, r, result;
    std::cout << "== Треугольник ==" << std::endl;
    std::cout << "Введите сторону: ";
    //std::cin >> a;
    a = read_data();
    std::cout << "Введите высоту, опущенную к данной стороне: ";
    //std::cin >> h;
    h = read_data();
    std::cout << "S = " << get_triangle_s(a, h) << std::endl;

    std::cout << "== Прямоугольник ==" << std::endl;
    std::cout << "Введите сторону a: ";
    //std::cin >> a;
    a = read_data();
    std::cout << "Введите сторону b: ";
    //std::cin >> b;
    b = read_data();
    std::cout << "S = " << get_box_s(a, b) << std::endl;

    std::cout << "== Круг ==" << std::endl;
    std::cout << "Введите радиус: ";
    //std::cin >> r;
    r = read_data();
    std::cout << "S = " << get_circle_s(r) << std::endl;

    return 0;
}

