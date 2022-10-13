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
        sscanf(buffer.c_str(), "%d", &temp);
        data.push_back(temp);
        std::cout << temp << std::endl;
    }

    return &data;
}

std::vector<int>* get_target_data (std::vector<int>* data) {
    std::vector<std::vector<int>> results;
    for (unsigned int start_index = 0; start_index < *data->size(); start_index++){
        for (unsigned int end_index = *data->size() - 1; end_index > 0; end_index--){


        }

    }

}

int main () {
    create_file_with_data();
    std::vector<int>* data = get_data_from_file();

}