//lesson 3
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>

#include <string>

#include <cstdlib>
int main() {
#if defined(WIN32)
    setlocale(LC_ALL, "Rus");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
    std::ofstream out_file("text.txt");
    if (!out_file){
        std::cout << "File creation error !" << std::endl;
    }
    out_file << "First line" << std::endl;
    out_file << "Second line" << std::endl;
    out_file << "1" << std::endl;
    out_file << "3,3" << std::endl;
    out_file << "-3,14" << std::endl;
    out_file << "Конец файла!" << std::endl;

    out_file.close();


    std::string buffer;

    std::ifstream file_in("text.txt");
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    float f_buff;
    while (file_in){
        getline(file_in, buffer);
        if(sscanf(buffer.c_str(), "%f", &f_buff) == 1){
            std::cout << f_buff << std::endl;
        }
    }

    return 0;
}


