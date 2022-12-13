//
// Created by yaroslav_admin on 23.11.22.
//

#include <iostream>

int main(){
    int in_days, in_months, in_years;
    int now_days, now_months, now_years;
    in_days = 16;
    in_months = 3;
    in_years = 2004;
    now_days = 13;
    now_months = 12;
    now_years = 2022;


    int dd = 0, dm = 0, dy = 0;
    dd = now_days - in_days;
    if (dd < 0){
        dd += 31;
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