//
// Created by yaroslav_admin on 24.11.22.
//

#ifndef MIREA_CPP_TASKS_DATA_HANDLER_HPP
#define MIREA_CPP_TASKS_DATA_HANDLER_HPP

#include <fstream>
#include <vector>
#include <sqlite3.h>
#include <iostream>
#include <map>
#include <cmath>

sqlite3 *db = 0; // хэндл объекта соединение к БД
char *err = 0;
int job_id = -1;

std::map<std::string, float> average_cache;

void print_student(int, char**, char**);
void print_students();
float find_average_for_student(int);
float find_average_for_student_19(int);
std::string make_marks_beautiful(std::string);
void find_average();
void find_average_mark_on_last_exams();

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
std::string GET_16_CMD = "SELECT * FROM students WHERE NOT MarksList LIKE \"%3%\"";
std::string GET_17_CMD = "SELECT * FROM students WHERE NOT (MarksList LIKE \"%F%\" OR MarksList LIKE \"%2%\" OR MarksList LIKE \"%5%\" OR MarksList LIKE \"%4%\" OR MarksList LIKE \"%P%\")";
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

float average = 0.0f;

void wipe_data(){
    data.clear();
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    // print_student(argc, argv, azColName);
    std::vector<std::string> line;
    for (int i = 0 ; i < argc; i++){
        line.push_back(argv[i] ? argv[i] : "-");
    }
    data.push_back(line);
    return 0;
}

float find_average_for_loaded_student(int student_id){
    if (average_cache.find(data[student_id][6]) != average_cache.end()){
        return average_cache[data[student_id][6]];
    }
    float sum = 0.0f;
    float count = 0.0f;
    std::string marks = data[student_id][6];
    for (char c : marks){
        switch (c) {
            case '2':
                sum += 2.0f;
                break;
            case '3':
                sum += 3.0f;
                break;
            case '4':
                sum += 4.0f;
                break;
            case '5':
                sum += 5.0f;
                break;
            case 'P':
                sum += 5.0f;
                break;
            case 'F':
                sum += 2.0f;
                break;
            default:
                count--;
                break;
        }
        count++;
    }
    return sum / count;

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


void proces_data_cmd4(){
    std::vector<std::vector<std::string>>  result;
    int is_ok = 0;
    for (auto line : data){
        is_ok = 0;
        std::string marks_raw = line[6];
        std::vector<std::string> marks_data = split(marks_raw);
        for (char i : marks_data[marks_data.size() - 1]){
            if (i == '2') {
                is_ok += 1;
            }
        }
        if (is_ok > 1){
            result.push_back(line);
        }
    }
    data = result;
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
            if (data[j][2] > data[j + 1][2])
                std::swap(data[j], data[j + 1]);
            else if (data[j][2] == data[j + 1][2] and data[j][1] > data[j + 1][1])
                std::swap(data[j], data[j + 1]);
            else if (data[j][1] == data[j + 1][1] and data[j][3] > data[j + 1][3])
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

void sort_on_birthday(){
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (data[j][8] > data[j + 1][8])
                std::swap(data[j], data[j + 1]);
        }
    }
}

void sort_on_birthday_year(){
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            std::string year_j = {data[j][8][0], data[j][8][1], data[j][8][2], data[j][8][3]};
            std::string year_jp = {data[j + 1][8][0], data[j + 1][8][1], data[j + 1][8][2], data[j + 1][8][3]};
            if (year_j > year_jp)
                std::swap(data[j], data[j + 1]);
        }
    }
}


void sort_on_birthday_month(){
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            std::string month_j = {data[j][8][4], data[j][8][5]};
            std::string month_jp = {data[j + 1][8][4], data[j + 1][8][5]};
            if (month_j > month_jp)
                std::swap(data[j], data[j + 1]);
        }
    }
}

void sort_on_average(){
    //std::cout << "SORT" << std::endl;
    std::vector<std::vector<std::string>> result = data;
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (find_average_for_student(j) > find_average_for_student(j + 1)) {
                //std::cout << av1 << " > " << av2 << std::endl;
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

void sort_on_average_19(){
    //std::cout << "SORT" << std::endl;
    std::vector<std::vector<std::string>> result = data;
    for (int i = 0; i < data.size();i++){
        for (int j = 0; j < data.size() - 1; j++){
            if (find_average_for_student_19(j) > find_average_for_student_19(j + 1)) {
                //std::cout << av1 << " > " << av2 << std::endl;
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

void proces_20_task(){
    //std::cout << "SORT" << std::endl;
    std::vector<std::vector<std::string>> result = data;
    for (int i = 0; i < data.size();i++){
        if(find_average_for_loaded_student(i) > average){
            for (int j = 0 ; j < data[0].size() + 1; j++) {
                if (j == data[0].size()){
                    std::cout << " " << find_average_for_loaded_student(i);
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
}
void proces_21_task(){
    //std::cout << "SORT" << std::endl;
    std::vector<std::vector<std::string>> result = data;
    for (int i = 0; i < data.size();i++){
        if(find_average_for_loaded_student(i) < average){
            for (int j = 0 ; j < data[0].size() + 1; j++) {
                if (j == data[0].size()){
                    std::cout << " " << find_average_for_loaded_student(i);
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
}
float round_2(float a){
    return round(a*100)/100;
}


void proces_22_task(){
    std::vector<std::vector<std::string>> result = data;
    for (int i = 0; i < data.size();i++){
        if(round_2(find_average_for_loaded_student(i)) == round_2(average)){
            for (int j = 0 ; j < data[0].size() + 1; j++) {
                if (j == data[0].size()){
                    std::cout << " " << round_2(find_average_for_loaded_student(i));
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
}
void run_sql_cmd(int cmd_id){
    wipe_data();
    int return_code = SQLITE_OK;
    std::string buffer;
    std::string req;
    switch (cmd_id) {
        case 1:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, nullptr, &err);
            break;
        case 2:
            return_code = sqlite3_exec(db, GET_B_STUDENTS.c_str(), callback, nullptr, &err);
            break;
        case 3:
            return_code = sqlite3_exec(db, GET_3_CMD.c_str(), callback, nullptr, &err);
            break;
        case 4:
            return_code = sqlite3_exec(db, GET_4_CMD.c_str(), callback, nullptr, &err);
            proces_data_cmd4();
            break;
        case 5:
            return_code = sqlite3_exec(db, GET_5_CMD.c_str(), callback, nullptr, &err);
            //print_students();
            //std::cout<< "=============\n\n";
            proces_data_cmd5();
            break;
        case 6:
            return_code = sqlite3_exec(db, GET_6_CMD.c_str(), callback, nullptr, &err);
            proces_data_cmd6();
            break;
        case 7:
            return_code = sqlite3_exec(db, GET_7_CMD.c_str(), callback, nullptr, &err);
            proces_data_cmd7();
            break;
        case 8:
            return_code = sqlite3_exec(db, GET_8_CMD.c_str(), callback, nullptr, &err);
            break;
        case 9:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, nullptr, &err);
            sort_on_alph();
            break;
        case 11:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, nullptr, &err);
            sort_on_start_year();
            break;
        case 10:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, nullptr, &err);
            sort_on_birthday_year();
            break;
        case 12:
            return_code = sqlite3_exec(db, GET_8_CMD.c_str(), callback, nullptr, &err);
            sort_on_start_year();
            break;
        case 13:
            return_code = sqlite3_exec(db, GET_B_STUDENTS.c_str(), callback, nullptr, &err);
            sort_on_birthday_year();
            break;
        case 14:
            return_code = sqlite3_exec(db, GET_14_CMD.c_str(), callback, nullptr, &err);
            break;
        case 15:
            return_code = sqlite3_exec(db, GET_15_CMD.c_str(), callback, nullptr, &err);
            break;
        case 16:
            return_code = sqlite3_exec(db, GET_16_CMD.c_str(), callback, nullptr, &err);
            break;
        case 17:
            return_code = sqlite3_exec(db, GET_17_CMD.c_str(), callback, nullptr, &err);
            break;
        case 18:
            return_code = sqlite3_exec(db, "SELECT * FROM students", callback, nullptr, &err);
            sort_on_average();
            break;
        case 19:
            return_code = sqlite3_exec(db, "SELECT * FROM students", callback, nullptr, &err);
            sort_on_average_19();
            break;
        case 20:
            std::cout << "Введите группу :";
            // std::cin >> buffer;
            getline(std::cin, buffer);
            req = "SELECT * FROM students WHERE StudyGroup = \"" + buffer + "\"";
            return_code = sqlite3_exec(db, req.c_str(), callback, nullptr, &err);
            if (data.empty()){
                std::cout << "Похоже такой группы нет !" << std::endl;
                exit(0);
            }
            find_average();
            std::cout << "Средний балл группы :" << average << std::endl;
            std::cout << "ID/ name / surname / Patronymic / Course / StudyGroup / MarksList / StartYear /Birthday / Average Mark" << std::endl;
            proces_20_task();
            break;
        case 21:
            std::cout << "Введите группу :";
            // std::cin >> buffer;
            getline(std::cin, buffer);
            req = "SELECT * FROM students WHERE StudyGroup = \"" + buffer + "\"";
            return_code = sqlite3_exec(db, req.c_str(), callback, nullptr, &err);
            if (data.empty()){
                std::cout << "Похоже такой группы нет !" << std::endl;
                exit(0);
            }
            find_average();
            std::cout << "Средний балл группы :" << average << std::endl;
            std::cout << "ID/ name / surname / Patronymic / Course / StudyGroup / MarksList / StartYear /Birthday / Average Mark" << std::endl;
            proces_21_task();
            break;
        case 22:
            std::cout << "Введите группу :";
            // std::cin >> buffer;
            getline(std::cin, buffer);
            req = "SELECT * FROM students WHERE StudyGroup = \"" + buffer + "\"";
            return_code = sqlite3_exec(db, req.c_str(), callback, nullptr, &err);
            if (data.empty()){
                std::cout << "Похоже такой группы нет !" << std::endl;
                exit(0);
            }
            find_average_mark_on_last_exams();
            std::cout << "Средний балл группы в последнюю сессию :" << average << std::endl;
            std::cout << "ID/ name / surname / Patronymic / Course / StudyGroup / MarksList / StartYear /Birthday / Average Mark on last exam" << std::endl;
            proces_22_task();
            break;
        case 27:
            req = "SELECT * FROM students";
            return_code = sqlite3_exec(db, req.c_str(), callback, nullptr, &err);
            sort_on_birthday();
            break;
        case 23:
            req = "SELECT * FROM students";
            return_code = sqlite3_exec(db, req.c_str(), callback, nullptr, &err);
            sort_on_birthday_year();
            break;
        case 24:
            req = "SELECT * FROM students";
            return_code = sqlite3_exec(db, req.c_str(), callback, nullptr, &err);
            sort_on_birthday_month();
            break;
        case 25:
            req = "SELECT * FROM students";
            return_code = sqlite3_exec(db, req.c_str(), callback, nullptr, &err);
            sort_on_alph();
            break;
        case 26:
            return_code = sqlite3_exec(db, GET_A_STUDENTS.c_str(), callback, nullptr, &err);
            sort_on_birthday_year();
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

void find_average(){
    float sum = 0.0f;
    float count = 0.0f;
    // std::cout << "Len :" << data.size() << std::endl;
    for (auto line : data){
        std::string marks = line[6];
        for (char c : marks){
            switch (c) {
                case '2':
                    sum += 2.0f;
                    break;
                case '3':
                    sum += 3.0f;
                    break;
                case '4':
                    sum += 4.0f;
                    break;
                case '5':
                    sum += 5.0f;
                    break;
                case 'P':
                    sum += 5.0f;
                    break;
                case 'F':
                    sum += 2.0f;
                    break;
                default:
                    count--;
                    break;
            }
            count++;
        }
    }
    average = sum / count;
}


void find_average_mark_on_last_exams(){
    float sum = 0.0f;
    float count = 0.0f;
    // std::cout << "Len :" << data.size() << std::endl;
    for (auto line : data){
        auto temp = split(line[6]);
        std::string marks = temp[temp.size() - 1];
        for (char c : marks){
            switch (c) {
                case '2':
                    sum += 2.0f;
                    break;
                case '3':
                    sum += 3.0f;
                    break;
                case '4':
                    sum += 4.0f;
                    break;
                case '5':
                    sum += 5.0f;
                    break;
                case 'P':
                    sum += 5.0f;
                    break;
                case 'F':
                    sum += 2.0f;
                    break;
                default:
                    count--;
                    break;
            }
            count++;
        }
    }
    average = sum / count;
}

float find_average_for_student(int student_id){
    if (average_cache.find(data[student_id][6]) != average_cache.end()){
        return average_cache[data[student_id][6]];
    }

    float sum = 0.0f;
    float count = 0.0f;
    wipe_data();
    sqlite3_exec(db, "SELECT * FROM students", callback, nullptr, &err);
    std::string marks = data[student_id][6];
    for (char c : marks){
        switch (c) {
            case '2':
                sum += 2.0f;
                break;
            case '3':
                sum += 3.0f;
                break;
            case '4':
                sum += 4.0f;
                break;
            case '5':
                sum += 5.0f;
                break;
            case 'P':
                sum += 5.0f;
                break;
            case 'F':
                sum += 2.0f;
                break;
            default:
                count--;
                break;
        }
        count++;
    }
    average_cache[data[student_id][6]] = sum / count;
    return sum / count;
}

std::map<std::string, float> average_cache19;
float find_average_for_student_19(int student_id){
    auto s_marks = split(data[student_id][6]);
    if (average_cache.find(s_marks[s_marks.size() - 1]) != average_cache.end()){
        return average_cache[data[student_id][6]];
    }

    float sum = 0.0f;
    float count = 0.0f;
    wipe_data();
    sqlite3_exec(db, "SELECT * FROM students", callback, nullptr, &err);
    std::string marks = s_marks[s_marks.size() - 1];
    for (char c : marks){
        switch (c) {
            case '2':
                sum += 2.0f;
                break;
            case '3':
                sum += 3.0f;
                break;
            case '4':
                sum += 4.0f;
                break;
            case '5':
                sum += 5.0f;
                break;
            case 'P':
                sum += 5.0f;
                break;
            case 'F':
                sum += 2.0f;
                break;
            default:
                count--;
                break;
        }
        count++;
    }
    average_cache19[data[student_id][6]] = sum / count;
    return sum / count;
}
void connect_to_db(){
    int return_code = sqlite3_open("students_min.db", &db);
    if( return_code ){
        fprintf(stderr, "Ошибка открытия/создания БД: %s\n", sqlite3_errmsg(db));
        exit(1);
    }
    else
        std::cout << "Подключение к базе данных прошло успешно!" << std::endl;
}

#endif //MIREA_CPP_TASKS_DATA_HANDLER_HPP
