//
// Created by yaroslav_admin on 13.10.22.
//
#include "../../cli_data_reader.h++"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void create_file_with_data(){
    std::ofstream out_file("text.txt");
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
    std::cout << "Готово !\033[0m" << std::endl;


}


bool is_correct_data_block(std::vector<int>* data){
    int size = data->size();
    std::vector<int> data_local = *data;
    if (size % 2 == 1)
        size--;
    for (unsigned int i = 0; i < (size / 2); i++){
        if (data_local[i] != data_local[data->size() - i - 1])
            return false;
    }
//    std::cout << "OK :" << std::endl;
//    for (int i : data_local){
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
    return true;
}

std::vector<int>* get_data_from_file(){
    std::string buffer;
    int temp;

    static std::vector<int> data;
    std::ifstream file_in("text.txt");
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
//        std::cout << "::" << temp << std::endl;
    }

    return &data;
}

std::vector<int>* get_target_data (std::vector<int>* data) {
    std::vector<std::vector<int>> results;
    std::vector<int> data_value;


    for (unsigned int start_index = 0; start_index < data->size(); start_index++){
        for (int end_index = data->size() - 1; end_index > -1; end_index--){
            if (end_index < start_index)
                break;
            std::vector<int> *temp = new std::vector<int>;
            data_value = *data;
            for (unsigned int i = start_index; i <= end_index; i++)
                temp->push_back(data_value[i]);
            if (is_correct_data_block(temp))
                results.push_back(*temp);
//            std::cout << start_index << " | " << end_index << std::endl;
            delete temp;

        }
    }
    int max_size = 0;
    static std::vector<int> max_part;

    for (auto combination : results){
        if (combination.size() > max_size){
            max_size = combination.size();
            max_part = combination;
        }
    }
    return &max_part;
}

int main () {
    create_file_with_data();
    std::vector<int>* data = get_data_from_file();
    std::vector<int>* result = get_target_data(data);
    std::cout << "Длина самого длинного искомого отрезка: " << result->size() << std::endl;
    std::cout << "Искомый отрезок: ";
    for (int i : *result){
        std::cout << i << " ";
    }
    std::cout << "Весь файл:" << std::endl;
    for (int i : *data){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

}