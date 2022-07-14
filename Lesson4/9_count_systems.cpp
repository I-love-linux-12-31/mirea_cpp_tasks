// Lesson 4

#include <iostream>
#include <cmath>

std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


void print_human_readable (int value[1024], int cs){
    if (cs > 36) {
        std::cout << "[";
        for (int i = 0; i < 1024; i++) {
            if (value[i] != -1) {
                std::cout << value[i];
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }
    else {
        for (int i = 0; i < 1024; i++) {
            if (value[i] != -1) {
                std::cout << alphabet[value[i]];
            }
        }
    }
    std::cout << std::endl;

}

int to_dec(int value[1024], int cs) {
    int result;
    int j = 0;
    while (value[j] != -1){
        result += pow(cs, j) * value[j];
        j++;
    }
    return result;
}


int get_index(char a) {
    for (int i = 0; i < 36; i++){
        if (alphabet[i] == std::toupper(a)){
            return i;
        }
    }
    return -1;
}


bool check_input_correct(std::string input, int cs){
    for (char i : input) {
        if (get_index(i) >= cs)
            return false;
    }
    return true;
}


int* to_any(int dec_value, int cs) {
    int pre_result[1024];
    for (int i = 0; i < 1024; i++){
        pre_result[i] = -1;
    }
    static int result[1024];
    for (int i = 0; i < 1024; i++){
        result[i] = -1;
    }
    int temp = dec_value;
    int j = 0;

    while (temp >= cs){
        //std::cout << temp << " div =" << temp / cs << " ost =" << temp % cs << std::endl;
        pre_result[1024 - (j + 1)] = temp % cs;
        temp = temp / cs;
        j++;
    }
    if (temp > 0){

        pre_result[1024 - (j + 1)] = temp;
    }


    j = 0;
    for (int i = 0; i < 1024; i++){
        if (pre_result[i] != -1) {
            result[j] = pre_result[i];
            j++;
        }
    }
    return result;

}


int read_data_to_dec(int cs){
    static int result;
    static char a[1024];

    for (int i = 0; i < 1024; i++){
        a[i] = ' ';
    }
    std::cout << "Введите число :" << std::endl;
    std::cin >> a;
    while (!check_input_correct(a, cs)){
        std::cout << "Ввод некоректен (Не соответствует заявленой системе счисления) !"<< std::endl;
        std::cout << "Введите число: ";
        // std::getline(std::cin, a);
        std::cin >> a;
    }

    char t;
    int j = 0;
    for (int i = 0; i < 1024; i++){
        t = a[1024 - (1 + i)];
        if (t != ' ' and t != '\n' and (int)t > 0 ){
            result = result + get_index(t) * pow(cs, j);
            j++;
        }
    }
    return result;
}

int main() {

    std::cout << "Введите систему счисления (целое число) :" << std::endl;
    int cs;
    std::cin >> cs;
    int data_in;
    data_in = read_data_to_dec(cs);

    std::cout << "Введите новую систему счисления (целое число) :" << std::endl;
    std::cin >> cs;
    print_human_readable(to_any(data_in, cs), cs);


    return 0;
}