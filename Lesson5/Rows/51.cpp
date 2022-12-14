//
// Created by yaroslav_admin on 29.09.22.
//
#include <iostream>
#include <string>


int main () {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    int cols, rows;
    std::cout << "Введите кол-во строк :" << std::endl;
    std::cin >> rows;
    std::cout << "Введите кол-во столбцов" << std::endl;
    std::cin >> cols;

    float data[rows][cols];

    std::string str_buff;

    std::string buff;
    getline(std::cin, str_buff); // void line !
    for (unsigned int i = 0; i < rows; i++){
        std::cout << "\033[32m > \033[0m";
        for (unsigned int j = 0; j < cols; j++){
            data[i][j] = 0;
        }

        getline(std::cin, str_buff);
        buff = "";
        unsigned int j = 0;
        for (unsigned int counter = 0; counter < str_buff.length(); counter++){
            if (str_buff[counter] == ' ' or str_buff[counter] == '\t'){
                sscanf(buff.c_str(), "%f", &data[i][j]);
                buff = "";
                j++;
            }
            else {
                buff += str_buff[counter];
            }
        }
        if (buff != ""){
            sscanf(buff.c_str(), "%f", &data[i][j]);
        }


    }
    double sum = 0;
    for (unsigned int i = 0; i < rows; i++){
        for (unsigned int j = 0; j < cols; j++){
                        if (j % 2 == 1){ // инверсия тк начинаем с 0 а пользователей с 1
                sum += data[i][j];
            }

        }
    }
    std::cout << "\033[94mИскомая сумма: \033[0m\033[1m" << sum << std::endl;

    return 0;
}