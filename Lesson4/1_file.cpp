//lesson 4
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>

#include <string>

#include <cstdlib>
int main() {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif

    std::ofstream out_file("text.txt");
    if (!out_file){
        std::cout << "File creation error !" << std::endl;
    }
    std::cout << "Введите 10 чисел в консоль. (Каждое с новой строки.) Они будут записаны в файл. :";
    std::string _buffer;
    float _float_buff;
    for (int i = 0;i < 10;i++){
        std::cin >> _buffer;
        while (sscanf(_buffer.c_str(), "%f", &_float_buff) != 1){
            std::cout << "Не корректный ввод! Введите число :" << std::endl;
            std::cin >> _buffer;
        }

        out_file << _buffer << std::endl;

    }

    out_file.close();

    std::string buffer;

    std::ifstream file_in("text.txt");
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    double buff;
    double result;
    while (file_in){
        getline(file_in, buffer);
        if(sscanf(buffer.c_str(), "%lf", &buff) == 1){
            // std::cout << int_buff << std::endl;
            result = result + buff;
        }
    }
    std::cout << "Сумма : " << result << std::endl;



    return 0;
}


