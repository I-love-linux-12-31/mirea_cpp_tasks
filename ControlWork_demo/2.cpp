//
// Created by yaroslav_admin on 13.11.22.
//
// Задача 2. Снова спиннеры.
#include <iostream>


int main(){
    int m;
    std::cin >> m;
    int s4 = 0, s3 = 0;
    //std::cout << s4 << std::endl;
    int k = m % 4;
    if (k == 0){
        if (m > 12){
            s3 = 4;
            s4 = m / 4 -3;
        } else{
            s4 = m / 4;
        }

    }
    else {
        s3 = m / 3;
        s4 = m / 4;
        if ((m % 2) > (m % 4))
            s3 = 0;
        else
            s4 = 0;

    }
    std::cout << s3 << std::endl << s4 << std::endl;
    return 0;
}