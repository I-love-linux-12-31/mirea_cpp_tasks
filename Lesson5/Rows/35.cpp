// Lesson 5

#include <iostream>


int main () {
    std::cout << "Введите строку :" << std::endl;
    std::string line;

    std::getline(std::cin, line);
    int count = 0;
    int max_spaces = 0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] == ' '){
            count++;
        }
        else {
            if (count > max_spaces){
                max_spaces = count;
            }
            count = 0;
        }
    }
    if (count >> 0 and max_spaces < count){
        max_spaces = count;
    }
    std::cout << "Максимальное число подряд идущих пробелов :" << max_spaces << std::endl;
    return 0;
}