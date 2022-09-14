// Lesson 5
#include <iostream>
#include <cmath>
#include <string>


double get_height () {
    std::string buffer;
    std::cout << "\033[33m->\033[0m";
    std::cin >> buffer;
    float float_buff;
    while (sscanf(buffer.c_str(), "%f", &float_buff) != 1 or float_buff < 0.0){

        std::cout << "\033[31mОшибка ввода !\033[0m Должно быть число (можно дробь) \033[31m>\033[0m 0 !" << std::endl;
        std::cout << "\033[33m->\033[0m";
        std::cin >> buffer;
    }
    //std::cout << "### :" << float_buff << std::endl;
    return (double)float_buff;

}

int main () {
    std::cout << "\033[32m**** Анализ роста учеников ****\033[0m" << std::endl;
    std::cout << "Введите рост (см) или 0 для завершения." << std::endl;
    double history[1024];
    double sum = 0.0;
    int count = 0;
    double temp = -1;
    while (true) {
        temp = get_height();
        if (temp == 0){
            break;
        }
        else {
            history[count] = temp;
            count++;
            sum += temp;
        }
    }
    double average = sum / count;
    std::cout << "Средний рост = " << average << " см" << std::endl;

    temp = 0.0;
    for (int i = 0; i < count; i++){
        if (history[i] > average){
            temp += 1.0;
        }
    }
    std::cout << "Рост выше среднего у " << (int)temp << " человек(a)." << std::endl;

    return 0;
}