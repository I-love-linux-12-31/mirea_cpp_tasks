#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int main() {
    //std::cout << "Hello, World!" << std::endl;
    setlocale(0, "ru_RU.UTF-8");
    //cout << "Ярослав Kuznetsov!" << endl;

    bool night, lamp, shtory;
    night = false;
    lamp = false;
    shtory = false;
    string buffer;
    cout << "На улице ночь y/n:\n";
    cin >> buffer;
    if (buffer == "y"){
        night = true;
    }

    cout << "Лампа включена y/n:\n";
    cin >> buffer;
    if (buffer == "y"){
        lamp = true;
    }

    cout << "Шторы опущены y/n:\n";
    cin >> buffer;
    if (buffer == "y"){
        shtory = true;
    }
    if (not night and not shtory or lamp){
        cout << "Светло\n";
    }
    else {
        cout << "Темно\n";
    }


