// Lesson 4
#include <iostream>


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

int main() {
    char line[128];
    for (int i = 0; i < 128; i++)
        line[i] = ' ';
    std::cout << "Введите число:" << std::endl;
    std::cin >> line;

    int result = 0;
    int current_level = 0;
    int temp = 0;
    for (int i = 0; i < 128; i++){
        char l = line[127 - i];
        if (l != ' ' and (int)l > 33){
            //std::cout << get_dec_value(l) << std::endl;
            temp = get_dec_value(l);
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