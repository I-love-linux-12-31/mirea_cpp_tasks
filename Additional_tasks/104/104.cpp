//
// Created by yaroslav_admin on 24.11.22.
//
#include "data_handler.hpp"
#include "commands.hpp"

#include <iostream>
#include <iomanip>
#include <sqlite3.h>





int main(int argc, char **argv){
    connect_to_db();

    cmd_demo();

    // закрываем соединение
    sqlite3_close(db);
    return 0;
}