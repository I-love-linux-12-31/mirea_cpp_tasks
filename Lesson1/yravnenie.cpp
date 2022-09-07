#include <iostream>
using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    setlocale(0, "ru_RU.UTF-8");
    //cout << "Ярослав Kuznetsov!" << endl;

    double c, b;
    cout << "\033[31mВведите c:\n";
    cin >> c;
    cout << "\033[33mВведите b:\n\033[0m";
    cin >> b;
    //bx + c = 0
    // bx = -c
    // x = -c / b
    cout << -1 * c / b << endl;
//    cout << a - b << endl;
//    cout << a * b << endl;
//    cout << a / b << endl;



    return 0;
}

