//Lesson5
#include <iostream>
#include "../cli_data_reader.h++"

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
    int a;
    int b;
    std::cout << "Данная программа вычисляет НОД чисел А и Б двумя способами по алгоритму Евклида." << std::endl;
    std::cout << "Введите целое число А > 0 :" << std::endl;
    a = get_int_more_0_from_user();
    std::cout << "Введите целое число Б > 0 :" << std::endl;
    b = get_int_more_0_from_user();

    std::cout << "НОД чисел :" << std::endl;
    std::cout << nod_1(a, b) << std::endl;
    std::cout << nod_2(a, b) << std::endl;
    return 0;
}
