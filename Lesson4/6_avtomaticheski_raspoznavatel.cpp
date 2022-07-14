// Lesson 4
#include <iostream>
#include <string>


int get_dec_value (char &t){
    switch (t) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}


bool is_correct_string(std::string str){
    for (unsigned int i = 0; i < str.length(); i++){
        char res2 = std::toupper(str[i]);
        if(get_dec_value(res2) == 0)
            return false;
    }
    return true;
}

int main() {
    std::string line;
    std::cout << "Введите число:" << std::endl;
    //std::cin >> line;
    line = " ";
    std::getline(std::cin, line);
    while(!is_correct_string(line)){
        std::cout << "Ввод некоректен! Введите римское число :";
        std::getline(std::cin, line);
    }

    int result = 0;
    int current_level = 0;
    int temp = 0;
    for (int i = 0; i < line.size(); i++){
        char l = line[line.size() - 1 - i];
        if (l != ' ' and (int)l > 33){
            //std::cout << get_dec_value(l) << std::endl;
            char res = std::toupper(l);
            temp = get_dec_value(res);
            if (temp < current_level){
                result -= temp;
            }
            else {
                current_level = temp;
                result += temp;
            }
        }

    }
    std::cout << result << std::endl;


}