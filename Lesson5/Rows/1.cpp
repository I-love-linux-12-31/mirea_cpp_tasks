// Lesson 5
#include <iostream>
#include <cmath>


double get_y (int &n) {
    double result = 0.0;

    double last_div = 0.0;
    for (int i = 1; i < n + 1; i++){
        result += (i / (last_div + sin(i)));
        last_div += sin(i);
    }
    return result;
}

int main () {
    int n;
    std::cout << "Введите N :" << std::endl;
    std::cin >> n;
    std::cout << " y(" << n <<") = " << get_y(n) << std::endl;
    return 0;
}