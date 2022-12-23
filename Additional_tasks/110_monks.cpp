//
// Created by yaroslav_admin on 02.11.22.
//

#include <iostream>
#include <map>
#include <vector>

#include "../cli_data_reader.h++"

std::map<u_int, u_int[3]> monks;

bool is_delimiter(char c){
    for (char i : " \t\n")
        if (c == i)
            return true;
    return false;
}

std::vector<u_int> split(std::string &str){
    std::vector<u_int> result;
    std::string buffer;
    int int_buffer;
    for(char i : str){
        if (!is_delimiter(i)){
            buffer += i;
        }
        else {
            if (!buffer.empty())
                if (sscanf(buffer.c_str(), "%d", &int_buffer) == 0){
                    std::cout << "Введено не число !\n";
                    exit(-1);
                }
                result.push_back((u_int)int_buffer);
            buffer.clear();
        }
    }
    if (!buffer.empty()) {
        //result.push_back(buffer);
        if (sscanf(buffer.c_str(), "%d", &int_buffer) == 0){
            std::cout << "Введено не число !\n";
            exit(-1);
        }

        result.push_back((u_int)int_buffer);
    }
    return result;
}


std::vector<u_int> find_teacher_trace (u_int monk){
    std::vector<u_int> result;
    if (monk == 1){
        return result;
    }
    if (monk < 1){
        std::cout << "Ввод некоректный!" << std::endl;
        exit(-1);
    }
    for (u_int i = monk - 1; i > 0; i--){
        if (monks.find(i) == monks.end()) { // Проверка валидности ключа.
            continue;
        }
        for (u_int j : monks[i]){
            if (j == monk){
                result.push_back(i);
            }
        }
    }
    if (result.size() == 0)
        return result;
    if (result[result.size() - 1] == 1){
        return result;
    }
    for (u_int i : find_teacher_trace(result[result.size() - 1])){
        if (i == 1){
            continue;
        }
        result.push_back(i);
    }
    return result;
}


int main(){
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    int n = 0;
    std::cout << "Сколько строк с информацией о монахах вы хотите ввести?" << std::endl;
    n = get_int_more_0_from_user();

    std::string buffer;
    for (u_int i = 0; i < n; i++){
        std::cout << "$ ";
        getline(std::cin, buffer);
        if (buffer.empty()){
            n += 1;
            std::cout << "Ввод некоректный!\n";
        }
        auto current_monk_data = split(buffer);
        if (current_monk_data.size() != 4){
            std::cout << "Ввод некоректный!\n";
            exit(-1);
        }
        monks[current_monk_data[0]][0] = current_monk_data[1];
        monks[current_monk_data[0]][1] = current_monk_data[2];
        monks[current_monk_data[0]][2] = current_monk_data[3];
    }


    std::cout << "Доступные команды 1, 2:" << std::endl;
    std::cout << "1) По номеру монаха узнать, был ли такой монах и если был, то кто были его учитель,\n"
                 "учитель его учителя и т.д. до самого Святого Павла" << std::endl;
    std::cout << "2) По двум монашеским номерам найти их общего ближайшего учителя." << std::endl;
    std::cout << "Вводить в формате: <номер команды> <аргумент 1> <*аргумент2>!" << std::endl;
    getline(std::cin, buffer);
    if (buffer.empty()){
        std::cout << "Ввод некоректен\n";
        exit(-1);
    }
    std::vector<u_int> command_data = split(buffer);
    std::vector<u_int> monks_trace;
    std::vector<u_int> monks_trace2;
    std::vector<u_int> monks_teachers;

    switch (command_data[0]){
        case 1:
            if (command_data[1] == 1){
                std::cout << "Монах - Святой Павел!" << std::endl;
                break;
            }
            monks_trace = find_teacher_trace(command_data[1]);
            if (monks_trace.empty()){
                std::cout << (int)command_data[1] << " - не монах !" << std::endl;
                break;
            }
            std::cout << command_data[1] << " – монах, его учителя :";
            for (auto i : monks_trace){
                std::cout << " " << i;
            }
            std::cout << std::endl;
            break;
        case 2:
            if (command_data[1] == 1 or command_data[2] == 1){
                std::cout << "У Святого Павла нет учителя !" << std::endl;
                break;
            }
            monks_trace = find_teacher_trace(command_data[1]);
            if (monks_trace.empty()){
                std::cout << (int)command_data[1] << " - не монах !" << std::endl;
                break;
            }
            monks_trace2 = find_teacher_trace(command_data[2]);
            if (monks_trace2.empty()){
                std::cout << (int)command_data[2] << " - не монах !" << std::endl;
                break;
            }

            for (u_int i: monks_trace){
                for (u_int j : monks_trace2){
                    if (i == j){
                        //34 и 41 – оба монахи, и их общий учитель 13
                        std::cout << command_data[1] << " и " << command_data[2] <<
                        " – оба монахи, и их общий учитель " << i << std::endl;
                        exit(0);
                    }
                }
            }
            std::cout << command_data[1] << " и " << command_data[2] <<
                      " – оба монахи, и их общий учитель Святой Павел (1)"<< std::endl;

            break;
        default:
            std::cout << "Неизвестная команда :" << command_data[0] <<"\n";
            return -1;
    }
    return 0;
}