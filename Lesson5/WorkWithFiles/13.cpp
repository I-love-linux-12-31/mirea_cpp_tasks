//
// Created by yaroslav_admin on 19.10.22.
//

#include "../../cli_data_reader.h++"
#include "../../useful_functions.h++"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


#define FILE_A "13_A.txt"
#define FILE_B "13_B.txt"
#define FILE_C "13_C.txt"

void create_file_with_data(){
    std::ofstream out_file(FILE_A);
    if (!out_file){
        std::cout << "File creation error !" << std::endl;
        exit(1);
    }

    int temp;
    int n;
    std::cout << "\033[1m\033[32mСколько чисел вы хотите записать в файл?" << std::endl;
    n = get_int_more_0_from_user();
    for (unsigned int i = 0; i < n; i++){
        std::cout << "\033[1m\033[32m ->";
        temp = get_any_int_from_user();
        //temp = get_int_more_0_from_user();
        out_file << temp << std::endl;
    }
    out_file.close();
    std::cout << "\033[0m" << std::endl;


}


void save_data_to_file(std::vector<int> &data, std::string filename){
    std::ofstream out_file(filename);
    if (!out_file){
        std::cout << "File creation error !" << std::endl;
        exit(1);
    }

    for (int i : data){
        out_file << i << std::endl;
    }
    out_file.close();
}

std::vector<int>* get_data_from_file(std::string filename){
    std::string buffer;
    int temp;

    static std::vector<int> data;
    std::ifstream file_in(filename);
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    while (file_in){
        getline(file_in, buffer);
        if (buffer == "")
            break;
        sscanf(buffer.c_str(), "%d", &temp);
        data.push_back(temp);
    }

    return &data;
}


int main () {
    create_file_with_data();
    std::cout << "Введённые числа сохранены в файл: " << FILE_A << std::endl;
    std::vector<int> data = *get_data_from_file(FILE_A);
    std::map<int, int> stats;
    for (int i : data) {
        // std::cout << i << std::endl;
        if (stats.find(i) != stats.end()) { // Проверка валидности ключа.
            stats[i] += 1;
        } else {
            stats[i] = 1;
        }
    }
    // std::cout << data.size() << std::endl;
    // std::cout << "DATA :" << std::endl;
    int max_value = -1;
    for (std::map<int, int> :: iterator iterator = stats.begin(); iterator != stats.end(); iterator++) {
         //std::cout << iterator->first << " : " << iterator->second << std::endl;
         if (iterator->second > max_value)
             max_value = iterator->second;
    }
    std::vector<int> result;
    for (std::map<int, int> :: iterator iterator = stats.begin(); iterator != stats.end(); iterator++) {
        if (iterator->second == max_value)
            result.push_back(iterator->first);
    }

    std::cout << "Числа, повторяющиеся больше всего, сохранены в файл: " << FILE_B << std::endl;
    save_data_to_file(result, FILE_B);

    for (unsigned int j = 0; j < result.size(); j++){
        for (unsigned int i = 0; i < result.size() - 1; i++){
            if(result[i + 1] > result[i]){
                std::swap(result[i + 1], result[i]);
            }
        }
    }
    std::cout << "Числа, повторяющиеся больше всего, были отсортированы сохранены в файл: " << FILE_C << std::endl;
    save_data_to_file(result, FILE_C);
    std::cout << "\033[34mВывести содержимое файлов? [y/n] \033[0m"<< std::endl;
    bool do_output = get_bool_from_user();
    if (do_output){
        std::cout << "Содержимое файла: " << FILE_A << std::endl;
        print_file(FILE_A);
        std::cout << "Содержимое файла: " << FILE_B << std::endl;
        print_file(FILE_B);
        std::cout << "Содержимое файла: " << FILE_C << std::endl;
        print_file(FILE_C);
        std::cout << "\033[0m" << std::endl;
    }


}