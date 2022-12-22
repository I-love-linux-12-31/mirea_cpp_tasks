#include <iostream>
using namespace std;

int main() {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    double a, b;
    cout << "Введите a:\n";
    cin >> a;
    cout << "Введите b:\n";
    cin >> b;
    
    cout << "Ответ :" << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;



    return 0;
}

