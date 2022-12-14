//
// Created by yaroslav_admin on 23.11.22.
//

#include <ctime>
#include <iostream>
#include <vector>

// 1900 - не високосный.
// Високосный должен делится на 400 или на 4
// просто деление на сто - НЕ високосный (если делится на сто то для високосности обязан делится на 400!)
std::vector<int> days_peer_month = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get_any_int_from_user() {
    int result;
    std::string buffer;
    getline(std::cin, buffer);
    while (sscanf(buffer.c_str(), "%d", &result) != 1)   {
        std::cout << "Не корректный ввод! Должно быть целое число, например 10 !" << std::endl;
        std::cout << "Введите число :";

        getline(std::cin, buffer);
    }
    return result;
}

int main(){
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    std::cout << "Данная программа вычисляет сколько прошло времении с рождения чаловека\nНеобходимо по очереди ввести день, месяц и год рождения.\n\033[31mПри вводе не целого числа будет учтена только его целая часть!\033[0m" << std::endl;
    int in_days, in_months, in_years;
    int now_days, now_months, now_years;
    int dd = 0, dm = 0, dy = 0;
    std::cout << "Введите день :";
    in_days = get_any_int_from_user();
    if (in_days > 31 or in_days < 1){
        std::cout << "Такого дня быть не может !!!\n";
        exit(0);
    }
    std::cout << "Введите месяц :";
    in_months = get_any_int_from_user();
    if (in_months > 12 or in_months < 1){
        std::cout << "Такого месяца быть не может !!!\n";
        exit(0);
    }
    std::cout << "Введите год :";
    in_years = get_any_int_from_user();

    if (days_peer_month[in_months] < in_days){
        std::cout << "Такой даты не существует!!!\n";
        exit(0);
    }
    if (in_months == 2 and in_days == 29 and not (
            in_years % 4 == 0 and in_years % 100 != 0 or
            in_years % 400 == 0
    )){
        std::cout << "Такой даты не существует!!!\n";
        exit(0);
    }


    time_t now = time(nullptr);
    tm *ltm = std::gmtime(&now);

    now_years = 1900 + ltm->tm_year;
    now_months = 1 + ltm->tm_mon;
    now_days = ltm->tm_mday;
//
//    now_years = 2022;
//    now_months = 3;
//    now_days = 16;

    std::cout << "Сегодня :" << now_days << "." << now_months << "." << now_years << std::endl;

    bool born_in_future = false;
    if (in_years * 365 + in_months * 31 + in_days > now_years * 365 + now_months * 31 + now_days){
        born_in_future = true;
        std::swap(now_years, in_years);
        std::swap(now_days, in_days);
        std::swap(now_months, in_months);
    }

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

    dy = dy + (now_years - in_years);
    if (born_in_future)
        std::cout << "До этого момента осталось :" << dy << " лет " << dm << " месяцев " << dd << " дней" << std::endl;
    else
        std::cout << "С этого момента прошло :" << dy << " лет " << dm << " месяцев " << dd << " дней" << std::endl;


}