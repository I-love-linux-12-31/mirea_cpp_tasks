//
// Created by yaroslav_admin on 19.10.22.
//
// Первый разднл !
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../../cli_data_reader.h++"

std::vector<std::string> data;
bool is_punctuation(char a){
    for (char i : "0123456789?/\\,.<>;:'\"[]{}()_-+=*&^%$#@!~` ”\t\n")
        if (a == i)
            return true;
    return false;
}

std::vector<std::string> split(std::string &str){
    std::vector<std::string> result;
    std::string buffer;
    for(auto i : str){
        if (!is_punctuation(i)){
            buffer += (char)std::tolower(i);
        }
        else {
            if (!buffer.empty())
                result.push_back(buffer);
            buffer.clear();
        }
    }
    if (!buffer.empty())
        result.push_back(buffer);
    return result;
}


bool exists_in_data (std::string &val){
    for (auto i : data){
        if (val == i)
            return true;
    }
    return false;
}

void load_data(std::string filename){
    std::ifstream file_in;
    file_in.open(filename);
    std::string buffer;

    while(std::getline(file_in, buffer)){
        //std::cout << ">>" << buffer << std::endl;
        for (auto s : split(buffer))
            if (!exists_in_data(s))
                data.push_back(s);
    }

}

bool str_a_is_more_than_b (std::string a, std::string b){
    for (unsigned int i; i < a.length();i++){
        if (i >= b.length())
            return true;
        if ((int)a[i] > (int)b[i])
            return true;
        if ((int)a[i] < (int)b[i])
            return false;
    }
}


void sort_data(){
    for (unsigned int j = 0; j < data.size(); j++){
        for (unsigned int i = 0; i < data.size() - 1; i++){
            if (str_a_is_more_than_b(data[i], data[i + 1])){
                //std::cout << "Swapping :" << data[i] << " | " << data[i + 1] << std::endl;
                std::swap(data[i], data[i + 1]);}
//                std::string _temp = data[i + 1];
//                data[i + 1] = data[i];
//                data[i] = _temp;

        }
    }


}

int main (){
    std::cout << "Данная программа читает слова из файла, сортирует их." << std::endl;

    std::string filename;
    std::cout << "Введите имя входного файла:" << std::endl;
    getline(std::cin, filename);
    load_data(filename);
    sort_data();
    sort_data();

    std::cout << "Записать отсортерованные слова в файл text_17_out.txt? [y/n]" << std::endl;
    bool do_file_out = get_bool_from_user();
    std::ofstream out_file;
    if (do_file_out)
        out_file.open("text_17_out.txt");

    for (auto w : data){
        if (do_file_out)
            out_file << w << std::endl;
        std::cout << w << std::endl;
    }
    if (do_file_out)
        out_file.close();
    std::cout << "!!!!" <<str_a_is_more_than_b("pharetra", "a") << std::endl;
    return 0;
}
