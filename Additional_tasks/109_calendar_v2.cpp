//
// Created by yaroslav_admin on 23.11.22.
//

#include <iostream>

int get_any_int_from_user() {
    int result;
    std::string buffer;
    getline(std::cin, buffer);
    while (sscanf(buffer.c_str(), "%d", &result) != 1) {
        std::cout << "Не корректный ввод! Должно быть целое число, например 10 !" << std::endl;
        std::cout << "Введите число :";

        getline(std::cin, buffer);
    }
    return result;
}

int main(){
    int in_days, in_months, in_years;
    int now_days, now_months, now_years;
    in_days = get_any_int_from_user();
    in_months = get_any_int_from_user();
    in_years = get_any_int_from_user();
    now_days = 13;
    now_months = 12;
    now_years = 2022;


    int dd = 0, dm = 0, dy = 0;
    dd = now_days - in_days;
    if (dd < 0){
        dd += 30;
        dm -= 1;
    }
    dm += now_months - in_months;
    if (dm < 0){
        dm += 12;
        dy -= 1;
    }
    dy = now_years - in_years;

    std::cout << dy << " " << dm << " " << dd << std::endl;


}