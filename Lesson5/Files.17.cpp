//
// Created by yaroslav_admin on 26.10.22.
//
// Task 17 from last files block


#include <iostream>
#include "../cli_data_reader.h++"
#include <fstream>
#include <vector>

std::vector<std::string> data;


int get_val_for_sort(std::string line){
    int result = 0;
    bool after_point = false;
    for (char c : line){
        if (c == '.'){
            after_point = true;
        }
        else
            if (after_point){
                result += ((int)c - 48);
            }
    }
    return result;
}


void sort_data(){
    for (int i = 0 ; i < data.size() + 7; i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (get_val_for_sort((data[j + 1])) > get_val_for_sort((data[j])))
                std::swap(data[j], data[j + 1]);
        }
    }
}

int main(){
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    std::cout << "Сколько чисел вы хотите ввести :" << std::endl;
    int n = get_int_more_0_from_user();
    std::ofstream file_out1("17_out_1.txt");
    std::ofstream file_out2("17_out_2.txt");

    std::string str_buffer;
    for (int i = 0 ; i < n; i++){
        std::cout << "->";
        getline(std::cin, str_buffer);
        data.push_back(str_buffer);
        file_out1 << data[data.size() - 1] << std::endl;
    }
    std::cout << "Эти числа записаны в файл 17_out_1.txt." << std::endl;
    sort_data();
    for (auto i : data){
        // std::cout << i << std::endl;
        file_out2 << i << std::endl;
    }
    std::cout << "Эти числа были отсортерованны по сумме знаков после запятой записаны в файл 17_out_2.txt." << std::endl;

    file_out1.close();
    file_out2.close();
}
