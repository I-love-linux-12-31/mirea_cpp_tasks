//lesson 5
#include <iostream>
#include <fstream>

#include <cstdio>  // sscanf requirements !!!
#include <cstdarg> // sscanf requirements !!!


#include <cstdlib>

#include <vector>


int main () {
    std::ofstream out_file("5_5_1_data.txt");
    if (!out_file){
        std::cout << "File creation error !" << std::endl;
        exit(1);
    }
    out_file << "Название;Цена;Возраст 1(с);Возраст 2(по)" << std::endl;
    out_file << "Кубики;200;0;10" << std::endl;
    out_file << "Кукла;700;2;8" << std::endl;
    out_file << "Машинка;400;2;8" << std::endl;
    out_file << "Компьютер;700000;8;999" << std::endl;
    out_file << "Железная дорога;1500;4;12" << std::endl;

    out_file.close();

    std::string headers;
    std::string buffer;

    std::vector<std::string> names;
    std::vector<float> prices;
    std::vector<int> age1;
    std::vector<int> age2;

    std::ifstream file_in("5_5_1_data.txt");
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    getline(file_in, headers);



    while (file_in){
        getline(file_in, buffer);
        int last_pos = -1;
        int8_t mode = 0;
        float float_buffer = 0;
        for (int i = 0; i < buffer.length(); i++){
            if (buffer[i] == ';' or i == buffer.length() - 1){
                std::string temp_str;
                if (i == buffer.length() - 1) {
                    for (int j = last_pos + 1; j < i + 1; j++) {
                        temp_str += buffer[j];
                    }
                }
                else {
                    for (int j = last_pos + 1; j < i; j++) {
                        temp_str += buffer[j];
                    }
                }
                if (mode == 0) {
                    names.push_back(temp_str);
                }
                else {

                    if(std::sscanf(temp_str.c_str(), "%f", &float_buffer) == 1){

                    }

                    switch (mode) {
                        case 1:
                            prices.push_back(float_buffer);
                            break;
                        case 2:
                            age1.push_back((int)float_buffer);
                            break;
                        case 3:
                            age2.push_back((int)float_buffer);
                            break;
                        default:;
                    }
                }
                last_pos = i;
                mode++;
            }
        }
    }

    float max_price = 0;
    std::cout << "Игрушки, цена которых не превышает 400 р., и которые подходят детям 8 лет :" << std::endl;
    for (int i = 0; i < names.size(); i++) {
        if (prices[i] <= 400 and age1[i] <= 8 and age2[i] >= 8){
            std::cout << names[i] << std::endl;
        }
        if (prices[i] > max_price){
            max_price = prices[i];
        }
    }
    std::cout << "Цена самой дорогой игрушки (игрушек) = " << max_price << std::endl;
    std::cout << "Игрушеки, которые подходят одновременно детям 4-х и 10-и лет :" << std::endl;
    for (int i = 0; i < names.size(); i++) {
        if (age1[i] <= 4 and age2[i] >= 4 and age1[i] <= 10 and age2[i] >= 10){
            std::cout << names[i] << " " << prices[i] << std::endl;
        }
    }

    return 0;
}


