//
// Created by yaroslav_admin on 03.10.22.
//

// Lesson 5

#include <iostream>
#include <vector>
#include <string>

#include <fstream>

#include "../../useful_functions.h++"

const std::vector<int> EMPTY_DATA = {0, 0, 0, 0, 0, -1};
std::vector<std::string> COUNTRIES = {
        "Австрия",
        "Германия",
        "Канада",
        "Китай",
        "Корея",
        "Норвегия",
        "Россия",
        "США",
        "Финляндия",
        "Япония"
};

std::vector<int> get_block () {
    std::vector<int> result = {};
    std::string buffer_2;
    std::string buffer = " ";
    getline(std::cin, buffer);


    //int_fast16_t counter;
    int int_buffer;
    // while (buffer != ""){
    for (unsigned int counter = 0; counter < buffer.size(); counter++) {
        if (buffer[counter] == ' ' or buffer[counter] == '\t'){
            sscanf(buffer_2.c_str(), "%d", &int_buffer);
            result.push_back(int_buffer);
            buffer_2 = " ";
        }
        else {
            buffer_2 += buffer[counter];
        }
    }
    if (buffer_2 != " "){
        sscanf(buffer_2.c_str(), "%d", &int_buffer);
        result.push_back(int_buffer);
        buffer_2 = " ";
    }

    return result;
}


void sort(std::vector<std::vector<int>> &data){
    std::vector<int> buffer;
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (data[j][4] < data[j + 1][4]){
                buffer = data[j];
                data[j] = data[j + 1];
                data[j + 1] = buffer;

            }
        }
    }
}

int main (){
    std::vector<std::vector<int>> stats;

    std::vector<int> current_country_result;
    for (unsigned int i = 0; i < COUNTRIES.size(); i++){
        stats.push_back(EMPTY_DATA);
        std::cout << COUNTRIES[i] << " -> ";
        current_country_result = get_block();
        stats[i][5] = i;

        stats[i][0] = current_country_result[0];
        stats[i][1] = current_country_result[1];
        stats[i][2] = current_country_result[2];

        stats[i][3] = current_country_result[0] + current_country_result[1] + current_country_result[2];
        stats[i][4] = 7 * current_country_result[0] + 6 * current_country_result[1] + 5 * current_country_result[2];

    }

    sort(stats);

    std::cout << std::endl;

    std::ofstream out_file("out.csv");
    if (!out_file){
        std::cout << "Ошибка создания файла !" << std::endl;
    }
    out_file << ";Страна;Золото;Серебро;Бронза;Всего;Очков" << std::endl;

    unsigned int c = 0;
    for (unsigned int i = 0; i < stats.size();i++){
        out_file << c + 1 << ";" << COUNTRIES[stats[i][5]]  <<  ";";
        for (unsigned int j = 0; j < stats[0].size() - 1; j++){
            if (j != stats[0].size() - 2)
                out_file << stats[i][j] << ";";
            else
                out_file << stats[i][j];
        }
        out_file << std::endl;
        c++;
    }
    out_file.close();
    std::cout <<  "Итоги зимней Олимпиады в Нагано, 1998 г посчитаны и доступны в таблице out.csv." << std::endl;
    //std::cout << data[0] << " " << data[1] << data[2] << std::endl;
    return 0;
}