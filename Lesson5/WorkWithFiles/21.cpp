//lesson 3
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>

#include <string>

#include <cstdlib>
int main() {

    char targets[5][2];
    //= "AEYUIO"
    targets[0][0] = 'a';
    targets[0][1] = 'A';

    targets[1][0] = 'e';
    targets[1][1] = 'E';

    targets[2][0] = 'u';
    targets[2][1] = 'U';

    targets[3][0] = 'i';
    targets[3][1] = 'I';

    targets[4][0] = 'o';
    targets[4][1] = 'O';
    int stats[5] = {0, 0, 0, 0, 0};



    std::string buffer;

    std::ifstream file_in("BigText.txt");
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    while (file_in){
        getline(file_in, buffer);
        for (int i = 0; i < buffer.length(); i++){
            //std::cout << (int)buffer[i] << " ";

            for (int j = 0; j < 5; j++){
                if ((char)buffer[i] == targets[j][0] or (char)buffer[i] == targets[j][1]){
                    stats[j] += 1;
                }
            }
        }
    }

    int max_val = -1;
    int max_val_id = -1;
    for (int j = 0; j < 5; j++){
        //std::cout << targets[j][1] << " : " << stats[j] << std::endl;
        if (stats[j] > max_val){
            max_val_id = j;
            max_val = stats[j];
        }
    }
    //std::cout << "===================================" << std::endl;
    std::cout << "Самая часто встречаемая гласная - "<< targets[max_val_id][1] << " ( " << max_val << " )" << std::endl;


    return 0;
}


