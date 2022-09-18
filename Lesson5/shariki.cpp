// Lesson 5
#include <iostream>

int factorial (int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}

int main () {
    int n = 10;
    std::cout << "Нашлось " << factorial(n - 1)*n << " варианта(ов)" << std::endl;

}