//
// Created by yaroslav_admin on 19.10.22.
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool get_bool_from_user(){
    std::string buffer;
    getline(std::cin, buffer);
    for (unsigned int i = 0; i < buffer.size(); i++){
        buffer[i] = toupper(buffer[i]);
    }
    if (buffer == "Y" or buffer == "YES" or buffer == "TRUE" or buffer == "OK" or buffer == "+")
        return true;
    if (buffer == "N" or buffer == "NO" or buffer == "FALSE" or buffer == "-")
        return false;
    std::cout << "Не корректный ввод! y/n :" << std::endl;
    return get_bool_from_user();
}

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
    if (!file_in){
        std::cout << "Нет такого файла !!!" << std::endl;
        exit(0);
    }
    std::string buffer;

    while(std::getline(file_in, buffer)){
        for (auto s : split(buffer))
            if (!exists_in_data(s))
                data.push_back(s);
    }

}

bool str_a_is_more_than_b (std::string a, std::string b){
    for (unsigned int i = 0; i < a.length();i++){
        if (i >= b.length())
            return true;
        if ((int)a[i] > (int)b[i])
            return true;
        if ((int)a[i] < (int)b[i])
            return false;
    }
    return false;
}


void sort_data(){
    for (unsigned int j = 0; j < data.size(); j++){
        for (unsigned int i = 0; i < data.size() - 1; i++){
            if (str_a_is_more_than_b(data[i], data[i + 1])){
                std::swap(data[i], data[i + 1]);
            }
        }
    }


}

int main (){
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    std::cout << "Данная программа читает слова из файла, сортирует их." << std::endl;

    std::string filename;
    std::cout << "Введите имя входного файла (Например LoremIpsum1.txt):" << std::endl;
    getline(std::cin, filename);
    load_data(filename);
    if (data.size() == 0){
        std::cout << "В файле нет слов !" << std::endl;
        exit(0);
    }
    sort_data();
    sort_data();

    std::cout << "Записать отсортированные слова в файл text_17_out.txt? [y/n]" << std::endl;
    bool do_file_out = get_bool_from_user();
    std::ofstream out_file;
    if (do_file_out)
        out_file.open("text_17_out.txt");

    std::cout << "Вывести отсортированные слова на экран? [y/n]" << std::endl;
    bool do_std_out = get_bool_from_user();

    if (do_std_out) {
        std::cout << "Отсортированные слова:" << std::endl;
        for (auto w: data) {
            if (do_file_out)
                out_file << w << std::endl;
            std::cout << w << std::endl;
        }
    }
    if (do_file_out)
        for (auto w: data) {
            out_file << w << std::endl;
        }
    out_file.close();
    return 0;
}
