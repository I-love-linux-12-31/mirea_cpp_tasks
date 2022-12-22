#include <iostream>
using namespace std;

int main() {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    cout << "Ярослав Kuznetsov!" << endl;
    return 0;
}

