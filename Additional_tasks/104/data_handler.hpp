//
// Created by yaroslav_admin on 24.11.22.
//

#ifndef MIREA_CPP_TASKS_DATA_HANDLER_HPP
#define MIREA_CPP_TASKS_DATA_HANDLER_HPP

#include <fstream>
#include <vector>
#include <sqlite3.h>
#include <iostream>

sqlite3 *db = 0; // хэндл объекта соединение к БД
char *err = 0;
int job_id = -1;

void print_student(int, char**, char**);
void print_students();

std::vector<std::vector<std::string>> data;

std::string GET_A_STUDENTS = "SELECT * FROM students WHERE NOT (MarksList LIKE \"%F%\" OR MarksList LIKE \"%2%\" OR MarksList LIKE \"%3%\" OR MarksList LIKE \"%4%\")";
std::string GET_B_STUDENTS = "SELECT * FROM students WHERE MarksList LIKE \"%4%\" AND NOT (MarksList LIKE \"%F%\" OR MarksList LIKE \"%2%\" OR MarksList LIKE \"%3%\")";
std::string GET_3_CMD = "SELECT * FROM students WHERE MarksList LIKE \"%3%\" AND NOT MarksList LIKE \"%3%3%\" ";
std::string GET_4_CMD = "SELECT * FROM students WHERE MarksList LIKE \"%#%2%#\"";
std::string GET_5_CMD = "SELECT * FROM students WHERE MarksList LIKE \"%5%\" AND MarksList LIKE \"%5%\"";
std::string GET_6_CMD = "SELECT * FROM students WHERE MarksList LIKE \"%3%\"";
std::string GET_7_CMD = "SELECT * FROM students WHERE MarksList LIKE \"%5%\" AND MarksList LIKE \"%4%\"";
std::string GET_8_CMD = "SELECT * FROM students WHERE Surname LIKE \"А%\"";
std::string GET_14_CMD = "SELECT * FROM students WHERE Surname LIKE \"Б%\"";
std::string GET_15_CMD = "SELECT * FROM students WHERE Surname LIKE \"В%\" OR Surname LIKE \"Г%\"";

std::vector<std::string> split(std::string &str){
    std::vector<std::string> result;
    std::string buffer;
    for(char i : str){
        if (i != '#'){
            buffer += i;
        }
        else {
            if (!buffer.empty())
                result.push_back(buffer);
            buffer.clear();
        }
    }
    if (!buffer.empty()) {
        result.push_back(buffer);
    }
    return result;
}

void wipe_data(){
    data.clear();
}

void print_headers(){
    std::cout << "ID/ name / surname / Patronymic / Course / StudyGroup / MarksList / StartYear /Birthday" << std::endl;
}
static int  callback(void*, int, char**, char**);

void proces_sql_error(int return_code){
    if (return_code != SQLITE_OK)
    {
        fprintf(stderr, "Ошибка SQL: %sn", err);
        sqlite3_free(err);
        exit(-1);
    }
}


void proces_data_cmd5(){
    std::vector<std::vector<std::string>>  result;
    bool is_ok = true;
    for (auto line : data){
        is_ok = true;
        std::string marks_raw = line[6];
        std::vector<std::string> marks_data = split(marks_raw);
        for (char i : marks_data[0]){
            if (i == '2' or i == '3' or i == '4' or i == 'F') {
                is_ok = false;
                break;
            }
        }
        if (is_ok){
            result.push_back(line);
        }
    }
    data = result;
}

void proces_data_cmd6(){
    std::vector<std::vector<std::string>>  result;
    bool is_ok = true;
    for (auto line : data){
        is_ok = true;
        std::string marks_raw = line[6];
        std::vector<std::string> marks_data = split(marks_raw);
        for (char i : marks_data[0]){
            if (i == '2' or i == '5' or i == '4' or i == 'F' or i == 'P') {
                is_ok = false;
                break;
            }
        }
        if (is_ok){
            result.push_back(line);
        }
    }
    data = result;
}
void proces_data_cmd7(){
    std::vector<std::vector<std::string>>  result;
    bool is_ok = true;
    bool one_4 = false;
    for (auto line : data){
        is_ok = true;
        std::string marks_raw = line[6];
        std::vector<std::string> marks_data = split(marks_raw);
        one_4 = false;
        for (char i : marks_raw){
            if (i == '4'){
                if (one_4){
                    is_ok = false;
                    break;
                }
                else
                    one_4 = true;
            }
            if (i == '2' or i == '3' or i == 'F') {
                is_ok = false;
                break;
            }
        }
        if (is_ok){
            result.push_back(line);
        }
    }
    data = result;
}

void sort_on_alph(){
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (data[j][1] > data[j + 1][1])
                std::swap(data[j], data[j + 1]);
        }
    }
}

void sort_on_start_year(){
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (data[j][7] > data[j + 1][7])
                std::swap(data[j], data[j + 1]);
        }
    }
}

void sort_on_start_birthday(){
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (data[j][8] > data[j + 1][8])
                std::swap(data[j], data[j + 1]);
        }
    }
}

void run_sql_cmd(int cmd_id){
    wipe_data();
    int return_code = SQLITE_OK;
    switch (cmd_id) {
        case 1:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, 0, &err);
            break;
        case 2:
            return_code = sqlite3_exec(db, GET_B_STUDENTS.c_str(), callback, 0, &err);
            break;
        case 3:
            return_code = sqlite3_exec(db, GET_3_CMD.c_str(), callback, 0, &err);
            break;
        case 4:
            return_code = sqlite3_exec(db, GET_4_CMD.c_str(), callback, 0, &err);
            break;
        case 5:
            return_code = sqlite3_exec(db, GET_5_CMD.c_str(), callback, 0, &err);
            //print_students();
            //std::cout<< "=============\n\n";
            proces_data_cmd5();
            break;
        case 6:
            return_code = sqlite3_exec(db, GET_6_CMD.c_str(), callback, 0, &err);
            proces_data_cmd6();
            break;
        case 7:
            return_code = sqlite3_exec(db, GET_7_CMD.c_str(), callback, 0, &err);
            proces_data_cmd7();
            break;
        case 8:
            return_code = sqlite3_exec(db, GET_8_CMD.c_str(), callback, 0, &err);
            break;
        case 9:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, 0, &err);
            sort_on_alph();
            break;
        case 11:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, 0, &err);
            sort_on_start_year();
            break;
        case 10:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, 0, &err);
            sort_on_start_birthday();
            break;
        case 12:
            return_code = sqlite3_exec(db, GET_8_CMD.c_str(), callback, 0, &err);
            sort_on_start_year();
            break;
        case 13:
            return_code = sqlite3_exec(db, GET_B_STUDENTS.c_str(), callback, 0, &err);
            sort_on_start_birthday();
            break;
        case 14:
            return_code = sqlite3_exec(db, GET_14_CMD.c_str(), callback, 0, &err);
            break;
        case 15:
            return_code = sqlite3_exec(db, GET_15_CMD.c_str(), callback, 0, &err);
            break;

    }
    proces_sql_error(return_code);


}

std::string make_marks_beautiful(std::string data_in){
    std::string result = "";
    const std::string CLEAR_STYLE = "\033[0m";
    for (char i : data_in){
        if (i == '#'){
            result += '\t';
            continue;
        }
        switch (i) {
            case '2':
                result += "\033[31m";
                break;
            case '3':
                result += "\033[93m";
                break;
            case '4':
                result += "\033[32m";
                break;
            case '5':
                result += "\033[96m";
                break;
            case 'F':
                result += "\033[91m";
                break;
            case 'P':
                result += "\033[92m";
                break;
            default:
                result += "\033[95m";
                break;
        }
        result += i + CLEAR_STYLE;
    }
    return result;
}

void print_student(int argc, char **argv, char **azColName){
    int i;
    for(i = 0; i<argc; i++) {
        if (i == 6){
            std::cout << " " << make_marks_beautiful(argv[i]).c_str();
        }
        else
            std::cout << " " << (argv[i] ? argv[i] : "-");
    }
    std::cout << std::endl;
}
void print_students(){
    if (data.empty())
        return;
    for(int i = 0; i< data.size(); i++) {
        for (int j = 0 ; j < data[0].size(); j++) {
            if (j == 6) {
                std::cout << " " << make_marks_beautiful(data[i][j]).c_str();
            } else
                std::cout << " " << data[i][j];
        }
        std::cout << std::endl;
    }
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    //print_student(argc, argv, azColName);
    std::vector<std::string> line;
    for (int i = 0 ; i < argc; i++){
        line.push_back(argv[i] ? argv[i] : "-");
    }
    data.push_back(line);
    return 0;
}

void connect_to_db(){
    int return_code = sqlite3_open("students", &db);
    if( return_code ){
        fprintf(stderr, "Ошибка открытия/создания БД: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
    else
        std::cout << "Подключение к базе данных прошло успешно!" << std::endl;
}

#endif //MIREA_CPP_TASKS_DATA_HANDLER_HPP
