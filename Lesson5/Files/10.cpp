//lesson 5
#include <iostream>
#include <fstream>

#include <cstdio>  // sscanf requirements !!!
#include <cstdarg> // sscanf requirements !!!

#include <vector>


std::string COMMAND_LINE_PREFIX = "\033[32m-> \033[0m";


void print_help () {
    std::cout << "\t\tДоступные команды :" << std::endl;
    std::cout << "0) Выход (\033[32mС сохранением\033[0m)" << std::endl;
    std::cout << "1) Просмотреть данные" << std::endl;
    std::cout << "2) Добавить студента" << std::endl;
    std::cout << "3) Выход (\033[31mБез сохранения !\033[0m)" << std::endl;

}
int get_command() {
    std::cout << "Введите команду :" << std::endl << COMMAND_LINE_PREFIX;

    std::string buffer = " ";
    std::cin >> buffer;
    int com = -1;
    std::sscanf(buffer.c_str(), "%d", &com);
    while ((com < 0 or com > 3)){
        std::cout << "Ввод некорректен ! Должен быть номер команды !" << std::endl << COMMAND_LINE_PREFIX;
        std::cin >> buffer;
        if (std::sscanf(buffer.c_str(), "%d", &com) != 1){
            com = -1;
        }
    }
    return com;
}

void add_student (std::vector<std::string> &data_surname, std::vector<std::string> &data_codes) {
    std::cout << "Введите фамилию :" << std::endl;
    std::string surname;
    std::cin >> surname;
    std::cout << "Введите шифр :" << std::endl;
    std::string code;
    std::cin >> code;

    data_surname.push_back(surname);
    data_codes.push_back(code);
}

void load_data (std::vector<std::string> &data_surname, std::vector<std::string> &data_codes) {
    std::ifstream file_in("students_data.txt");
    if (!file_in){
        std::cout << "" << std::endl;
        return;
    }
    std::string buffer;
    while (file_in){
        getline(file_in, buffer);
        int last_pos = -1;
        int8_t mode = 0;
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
                    data_surname.push_back(temp_str);
                }
                else {
                    data_codes.push_back(temp_str);
                }
                last_pos = i;
                mode++;
            }
        }
    }

}
void save_data (std::vector<std::string> &data_surname, std::vector<std::string> &data_codes) {
    std::ofstream out_file("students_data.txt");
    if (!out_file){
        std::cout << "Не удалось записать данные !" << std::endl;
        exit(1);
    }
    for (unsigned int i = 0; i < data_surname.size(); i++){
        out_file << data_surname[i] + ";" + data_codes[i] << std::endl;
    }
    out_file.close();

}
void show_data (std::vector<std::string> &data_surname, std::vector<std::string> &data_codes) {
    std::cout << "Фамилия\t\tШифр" << std::endl;
    for (unsigned int i = 0; i < data_surname.size(); i++){
        std::cout << "\033[35m" + data_surname[i] + "\t\033[34m" + data_codes[i] + "\033[0m" << std::endl;
    }

}

void sort_data_and_fix_bugs (std::vector<std::string> &data_surname, std::vector<std::string> &data_codes) {
    auto zero_index = data_surname.cbegin();
    std::string temp;
    for (unsigned int i = 0; i < data_surname.size(); i++){
        for (unsigned int j = 0; j < data_surname.size() - 1; j++){
            if (data_surname[j + 1] < data_surname[j]){
                temp = data_surname[j + 1];
                data_surname[j + 1] = data_surname[j];
                data_surname[j] = temp;
            }
            if (data_codes[j] == data_codes[j + 1]){
                // Баг:
                // Если в файле 1 запись она дублируется !!!
                //
                // Удаление дубля !
                data_surname.erase(zero_index + j);
                data_codes.erase(zero_index + j);
                return sort_data_and_fix_bugs(data_surname, data_codes);
            }
        }
    }

}
int main() {
    static std::vector<std::string> surnames;
    static std::vector<std::string> codes;

    load_data(surnames, codes);
    sort_data_and_fix_bugs(surnames, codes);
    print_help();
    int command = -1;
    while (command != 0){
        switch (get_command()) {
            case 1:
                sort_data_and_fix_bugs(surnames, codes);
                show_data(surnames, codes);
                break;
            case 2:
                add_student(surnames, codes);
                break;
            case 3:
                command = 0;
                break;
            default:
                command = 0;
                sort_data_and_fix_bugs(surnames, codes);
                save_data(surnames, codes);
                break;
        }
    }


}
