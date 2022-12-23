//
// Created by yaroslav_admin on 21.12.22.
//

#include <iostream>
#include <fstream>

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
    int neighbors;
    for (int line_id = 0 ; line_id < 21; line_id++){
        for (int item_id = 0 ; item_id < 21; item_id++){
            if (now[line_id][item_id] < 0) {
                next[line_id][item_id] = -10;
                continue;
            }

            neighbors = 0;
            for (
                    int neighbor : {
                        now[line_id][item_id + 1],
                        now[line_id][item_id - 1],
                        now[line_id + 1][item_id],
                        now[line_id - 1][item_id],
                    }
                    ){
                if (neighbor > 0)
                    neighbors++;
            }
            if (neighbors == 2 or neighbors == 3)
                next[line_id][item_id] = now[line_id][item_id] + 1;
            else
                next[line_id][item_id] = 0;

            if (next[line_id][item_id] >= 13)
                next[line_id][item_id] = 0;

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

bool is_all_dead(int data[21][21]){
    for (int line_id = 0 ; line_id < 21; line_id++){
        for (int item_id = 0 ; item_id < 21; item_id++){
            if (data[line_id][item_id] > 0)
                return false;
        }
    }
    return true;
}

int get_alive_count(int data[21][21]){
    int res = 0;
    for (int line_id = 0 ; line_id < 21; line_id++){
        for (int item_id = 0 ; item_id < 21; item_id++){
            if (data[line_id][item_id] > 0)
                res++;
        }
    }
    return res;
}

int main(){
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    auto now = get_data_from_file();
    // print_data(now);

    std::cout << "Сколько поколений рассчитать :" << std::endl;
    int iterations = get_int_above_or_0_from_user();
    if (iterations == 0){
        std::cout << "Нечего вычислять !" << std::endl;
        save_to_file("work.out", now);
        exit(0);
    }

    std::cout << "Исходное поле из микробов 1-ого поколния!" << std::endl;
    print_data(now);
    for (int i = 0 ; i < iterations; i++){
        if (is_all_dead(now)){
            std::cout << "В " << i + 1  << " поколения все умерли!" << std::endl;
            break;
        }
        now = make_next_move(now);
        std::cout << " После " << i + 1  << " поколения осталось " << get_alive_count(now) << " микробов." << std::endl;
        print_data(now);
        save_to_file("work_iteration_" + std::to_string(i + 1) + ".out", now);
    }
    save_to_file("work.out", now);
    return 0;
}
