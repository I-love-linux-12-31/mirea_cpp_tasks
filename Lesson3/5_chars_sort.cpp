//lesson 3
#include <iostream>

int main() {
    char my_string[31] = "AJFHTDHNCHWTYJDBGYDXZTUIKNFDJL";
    char temp;
    for (int i=0;i < 29; i++){
        for (int j=0;j < 29; j++){
            if (my_string[j + 1] < my_string[j]){
                temp = my_string[j];
                my_string[j] = my_string[j + 1];
                my_string[j + 1] = temp;
            }
        }
    }
    std::cout << my_string << std::endl;

    return 0;
}


