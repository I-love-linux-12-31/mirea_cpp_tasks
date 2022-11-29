//
// Created by yaroslav_admin on 26.11.22.
//

#ifndef CPP_1_COURSE_PART1_COMMANDS_HPP
#define CPP_1_COURSE_PART1_COMMANDS_HPP
#include "data_handler.hpp"


void print_data_for_8_command(){
    for (auto line : data){
        std::cout << line[1] << " " << line[2] << " : " << make_marks_beautiful(line[6]) << std::endl;
    }
}

void print_data_for_14_command(){
    for (auto line : data){
        std::cout << line[1] << " " << line[2] << " : " << line[8] << std::endl;
    }
}

void print_data_for_15_command(){
    for (auto line : data){
        auto temp = split(line[6]);
        std::cout << line[1] << " " << line[2] << " : " << make_marks_beautiful(temp[temp.size() - 1]) << std::endl;
    }
}

void print_data_for_16_command(){
    for (auto line : data){
        std::cout << line[2] << " : " << line[8] << std::endl;
    }
}
void print_data_for_18_command(){
    for(int i = 0; i< data.size(); i++) {
        for (int j = 0 ; j < data[0].size() + 1; j++) {
            if (data[0].size() == j){
                std::cout << " " << find_average_for_student(i);
                continue;
            }
            if (j == 6) {
                std::cout << " " << make_marks_beautiful(data[i][j]).c_str();
            } else
                std::cout << " " << data[i][j];
        }
        std::cout << std::endl;
    }
}
//void print_only_fios(){
//    for (auto line : data){
//        std::cout << line[0] << " " << line[1] << " " << line[2] << std::endl;
//    }
//}

void command(int cmd){
    bool print = true;
    for (int i : {14, 15, 16, 17, 18, 20, 21}){
        if (i == cmd)
            print = false;
    }

    std::cout << "Выполняю команду..." << std::endl;
    run_sql_cmd(cmd);
    std::cout << "\033[32mУспешно !\033[0m" << std::endl;
    if (data.empty())
        std::cout << "\033[31mНет подходящих результатов !\033[0m" << std::endl;
    else if (print) {
        print_headers();
        print_students();
    }
    else{
        switch (cmd) {
            case 8:
                std::cout << "Name / Surname / Marks" << std::endl;
                print_data_for_8_command();
                break;
            case 14:
                print_data_for_14_command();
                break;
            case 15:
                print_data_for_15_command();
                break;
            case 16:
                print_data_for_16_command();
                break;
            case 17:
                print_data_for_16_command();
                break;
            case 18:
                print_data_for_18_command();
                break;

        }
    }
}

#endif //CPP_1_COURSE_PART1_COMMANDS_HPP
