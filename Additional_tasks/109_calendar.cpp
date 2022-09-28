//
// Created by yaroslav_admin on 28.09.22.
//

#include "../Lib/DateTime/datetime.h"

#include <chrono>
#include <ctime>
#include <iostream>
int main(){

    int year;
    int month;
    int day;
    std::cout << "Введите дату рождения (Год): " << std::endl;
    std::cin >> year;
    std::cout << "Введите дату рождения (Месяц): " << std::endl;
    std::cin >> month;
    std::cout << "Введите дату рождения (День): " << std::endl;
    std::cin >> day;

    jed_utils::datetime dt(year, month, day);
    jed_utils::datetime dt_now = jed_utils::datetime();

    std::cout << "С этого момента прошло: ";
    std::cout << dt_now.get_year() - dt.get_year() << " дней, ";
    std::cout << dt_now.get_month() - dt.get_month() << " месяцов, ";
    std::cout << dt_now.get_day() - dt.get_day() << " дней.";

    // todo: error !
    /*
     Введите дату рождения (Год):
    2004
    Введите дату рождения (Месяц):
    12
    Введите дату рождения (День):
    16
    С этого момента прошло: 18 дней, -3 месяцов, 12 дней.


     */




}
