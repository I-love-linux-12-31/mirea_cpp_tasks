//lesson 4

#include <iostream>


int main() {
    char a[13][64];

    for (int y = 0; y < 13; y++){
        for (int x = 0; x < 64; x++){
            //std::cout << a[y][x];
            if (y < 6 and x < 16) {
                if (y % 2 != 1) {
                    if (x % 2 != 1) {
                        a[y][x] = '*';
                    } else {
                        a[y][x] = ' ';
                    }
                }
                else {
                    if (x % 2 == 1) {
                        a[y][x] = '*';
                    } else {
                        a[y][x] = ' ';
                    }

                }

            }
            else {
                if (x == 16 and y < 6) {
                    a[y][x] = ' ';
                }
                else {
                    a[y][x] = '#';
                }

            }
        }
    }


    for (int y = 0; y < 13; y++){
        for (int x = 0; x < 64; x++){
            std::cout << a[y][x];
        }
        std::cout << std::endl;
    }


    return 0;
}

