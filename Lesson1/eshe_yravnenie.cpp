#include <iostream>
#include <math.h>
using namespace std;

int main() {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif

    double a, b, c, descr;
    cout << "Введите a:\n";
    cin >> a;
    cout << "Введите b:\n";
    cin >> b;
    cout << "Введите b:\n";
    cin >> c;
    if (a == 0){
        cout << "Result : x =" << -1 * c / b << endl;
    }
    else {
        descr = (b * b) - (4 * a * c);
        if (descr < 0) {
            cout << "Нет решений\n";
        }
        else {
            if (descr == 0){

                cout << "Result : x =" << (-1 * b) / (2 * a) << endl;
            }
            else {
                cout << "Result : x1 =" << (-1 * b + sqrt(descr)) / (2 * a) << endl;
                cout << "Result : x2 =" << (-1 * b - sqrt(descr)) / (2 * a) << endl;
            }
        }


    }
//    cout << a - b << endl;
//    cout << a * b << endl;
//    cout << a / b << endl;



    return 0;
}

