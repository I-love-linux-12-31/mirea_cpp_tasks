//lesson 2

#include <iostream>
#include <cmath>

double double_abs(double a){
    if (a < 0){
        return -1 * a;
    }
    return a;
}

double get_w (double a, double x){
    if (double_abs(x) < 1){
        return a * log(double_abs(x));
    }
    else{
        return sqrt(a - pow(x, 2));
    }

}

int main() {
    double a, x;
    std::cout << "Введите a :";
    std::cin >> a;
    std::cout << "Введите x :";
    std::cin >> x;
    std::cout << "Ответ w = " << get_w(a, x) << std::endl;

    return 0;
}

