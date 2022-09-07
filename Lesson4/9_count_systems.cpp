#include <iostream>
#include <cmath>
#include <string>

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

        pre_result[1024 - (j + 1)] = temp % cs;
        temp = (int)(round((double)temp / (double)cs));
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

//char[128] change_cs (char[128] value, int cs_old, cs_new) {
//
//    return ' ';
//}

int main() {

    int test[1024];
    for (int i = 0; i < 1024; i++){
        test[i] = -1;
    }
    test[0] = 1;
    test[1] = 1;

    int* data_link;
    data_link = to_any(325366576, 100);
    //std::cout << data_link[1];
    print_human_readable(data_link, 100);


    return 0;
}