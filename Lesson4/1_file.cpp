//lesson 4
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
//    out_file << "First line" << std::endl;
//    out_file << "Second line" << std::endl;
//    out_file << "1" << std::endl;
//    out_file << "3.3" << std::endl;
//    out_file << "-3.14" << std::endl;
//    out_file << "Конец файла!" << std::endl;
   for (int i = 0;i < 10;i++){
       out_file << "1" << std::endl;

   }

    out_file.close();


    std::string buffer;

    std::ifstream file_in("text.txt");
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    double buff;
    double result;
    while (file_in){
        getline(file_in, buffer);
        if(sscanf(buffer.c_str(), "%lf", &buff) == 1){
            // std::cout << int_buff << std::endl;
            result = result + buff;
        }
    }
    std::cout << result << std::endl;



    return 0;
}


