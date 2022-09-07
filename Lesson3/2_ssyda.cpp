//lesson 3

// IN:
// 2
// 0.0448378
// 4

// OUT:
// p = 3



#include <iostream>
#include <cmath>

double get_m(double s, double p, double n) {
    double r = p / 100;
    return (s * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}


double round_6(double val){
    return round(val * 1000000) / 1000000 ;
}

int main() {

    double s, n, m;
    //S, p, n
    std::cout << "Введите s :" << std::endl;
    std::cin >> s;
    std::cout << "Введите m :" << std::endl;
    std::cin >> m;
    std::cout << "Введите n :" << std::endl;
    std::cin >> n;

    double _m = 0.0;
    double p = 0.0;
    for (int _p = 0; _p < 100000; _p++) {
        p = (double)_p / 1000;


        _m = get_m(s, p, n);

        if (round_6(m) == round_6(_m)) { // !!! (0.0448378 == 0.0448378) = false !!!

            std::cout << "p = ";
            std::cout << p << std::endl;
            return 0;
        }
    }
    std::cout << "Такого p не нашлось !" << std::endl;

    return 0;
}


