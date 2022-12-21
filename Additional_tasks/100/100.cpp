//
// Created by yaroslav_admin on 21.12.22.
//

#include <iostream>
#include <fstream>
// #include <>

int get_int_above_or_0_from_user(){
    int result;
    std::string buffer;
    getline(std::cin, buffer);
    while(sscanf(buffer.c_str(), "%d", &result) != 1 or result < 0){
        std::cout << "Не корректный ввод! Должно быть целое число > 0, например 16 !" << std::endl;
        std::cout << "Введите число :";
        getline(std::cin, buffer);
    }
    return result;
}

auto get_data_from_file(){
    static int res[21][21];
    std::ifstream data_in("work.dat");
    if (!data_in){
        std::cout << "Файл с входными данными не найден!" << std::endl;
        exit(0);
    }
    std::string line;
    for (int line_id = 0 ; line_id < 21; line_id++){
        std::getline(data_in, line);
        if (line.length() != 21 or line.empty())
        {
            std::cout << "Файл с входными данными некорректен!" << std::endl;
            exit(0);
        }

        for (int item_id = 0 ; item_id < 21; item_id++){
            if (std::toupper(line[item_id]) == 'X')
                res[line_id][item_id] = 1;
            else
                if (line[item_id] == '#')
                    res[line_id][item_id] = -10;
                else
                    res[line_id][item_id] = 0;
        }
    }

    return res;

}


void save_to_file(std::string filename, int data[21][21]){
    std::ofstream data_out(filename);
    if (!data_out){
        std::cout << "Файл с выходными данными не доступен для записи!" << std::endl;
        exit(0);
    }
    for (int line_id = 0 ; line_id < 21; line_id++){
        for (int item_id = 0 ; item_id < 21; item_id++){
            data_out << data[line_id][item_id];
        }
        data_out << std::endl;
    }
}

auto make_next_move(int now[21][21]){
    static int next[21][21];
    for (int line_id = 0 ; line_id < 21; line_id++){
        for (int item_id = 0 ; item_id < 21; item_id++){
            next[line_id][item_id] = now[line_id][item_id] + 1;
            if (now[line_id][item_id] < 0)
                next[line_id][item_id] = -10;
        }
    }
    return next;
}


void print_data(int data[21][21]){
    for (int line_id = 0 ; line_id < 21; line_id++){
        for (int item_id = 0 ; item_id < 21; item_id++){
            if (data[line_id][item_id] == 0){
                std::cout << " \t";
            }
            if (data[line_id][item_id] < 0){
                std::cout << "\033[33m#\033[0m\t";
            }
            if (data[line_id][item_id] > 0) {
                std::cout << "\033[32m" << data[line_id][item_id] << "\033[0m\t";
            }
        }
        std::cout << std::endl;
    }
}

int main(){
    auto now = get_data_from_file();
    // print_data(now);

    std::cout << "Сколько поколений рассчитать :" << std::endl;
    int iterations = get_int_above_or_0_from_user();
    if (iterations == 0){
        save_to_file("work.out", now);
        exit(0);
    }
    for (int i = 0 ; i < iterations; i++){
        now = make_next_move(now);
        save_to_file("work_iteration_" + std::to_string(i + 1) + ".out", now);
    }
    print_data(now);
    save_to_file("work.out", now);

    return 0;
}
