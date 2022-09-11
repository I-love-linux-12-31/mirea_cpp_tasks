// lesson 4
#include <iostream>
#include <cmath>
// TODO : Check alg.!!!

static double a[3][4];
static double b[5][2];

static double c[3][2]; //



void init() {
    a[0][0] = 5.0;
    a[0][1] = 2.0;
    a[0][2] = 0.0;
    a[0][3] = 10.0;

    a[1][0] = 3.0;
    a[1][1] = 5.0;
    a[1][2] = 2.0;
    a[1][3] = 5.0;

    a[2][0] = 20.0;
    a[2][1] = 0.0;
    a[2][2] = 0.0;
    a[2][3] = 0.0;


    b[0][0] = 1.2;
    b[0][1] = 0.5;

    b[1][0] = 2.8;
    b[1][1] = 0.4;

    b[2][0] = 5.0;
    b[2][1] = 1.0;

    b[3][0] = 2.0;
    b[3][1] = 1.5;

}


void multiply() {

    for(int i=0; i < 3; i++){

        for(int j=0; j < 2; j++)
        {
            c[i][j]=0;
            for(int k=0; k < 4; k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
    }


}

int main(){
    init();
    multiply();

    for (int y = 0; y < 3; y++ ){
        for (int x = 0; x < 2; x++ ){
            std::cout << c[y][x] << " ";
        }
        std::cout << std::endl;

    }


    std::cout << b[3][1] << std::endl;
}