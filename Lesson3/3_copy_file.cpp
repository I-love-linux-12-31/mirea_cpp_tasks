//lesson 3
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>

#include <string>

#include <cstdlib>
int main() {
    std::ofstream out_file("text.txt");
    if (!out_file){
        std::cout << "File creation error !" << std::endl;
    }
    out_file << "First line" << std::endl;
    out_file << "Second line" << std::endl;
    out_file << "Конец файла!" << std::endl;

    out_file.close();


    std::string buffer;

    std::ifstream file_in("text.txt");
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    while (file_in){
        getline(file_in, buffer);
        std::cout << buffer << std::endl;
    }




    return 0;
}


