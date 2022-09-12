//Lesson5
#include <iostream>

double nod_1 (double a, double b) { // Вычитанием
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }

    }
    return a;
}


double nod_2 (double a, double b) { // Делением
    while (a != 0 and b != 0) {
        if (a > b) {
            a = (int)a % (int)b;
        }
        else {
            b = (int)b % (int)a;
        }

    }
    return a + b;
}


int main () {
    int a = 4;
    int b = 8;
    std::cout << nod_1(a, b) << std::endl;
    std::cout << nod_2(a, b) << std::endl;
    return 0;
}
