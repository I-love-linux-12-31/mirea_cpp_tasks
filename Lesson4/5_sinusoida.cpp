// lesson 4
#include <iostream>
#include <cmath>

double func(double x){
    return sin(x);
}

int main(){
    char output[16][128];

    for(int y=0; y<16; y++){
        for(int x=0; x<128; x++){
            output[y][x] = ' ';
        }
    }

    double val;
    for(int x=0; x<128; x++){
        val = func(x);
        if (val < 7 and val > -7) {
            output[ 8 + (int)round(val)][x] = '#';
        }
        else {
            std::cout << "ERR \n";
        }
    }

    for(int y=0; y<16; y++){
        for(int x=0; x<128; x++){
            std::cout << output[y][x];
        }
        std::cout << std::endl;
    }

}