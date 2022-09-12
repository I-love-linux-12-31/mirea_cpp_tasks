// lesson 4
#include <iostream>

static double a[3][4];
static double b[5][2];

static double c[3][2];



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
            std::cout << c[y][x] << "\t";
        }
        std::cout << std::endl;

    }

    double traders_statuses[3][2];
    double total_result = 0;

    for (int trader_id = 0; trader_id < 3; trader_id++){
        traders_statuses[trader_id][0] = 0.0;
        traders_statuses[trader_id][1] = 0.0;

        for (int i = 0; i < 4; i++){
            traders_statuses[trader_id][0] += a[trader_id][i] * (b[i][0] - b[i][1]);
            traders_statuses[trader_id][1] += a[trader_id][i] * b[i][1];
        }
        //std::cout << "Trader " << trader_id << " : " << traders_statuses[trader_id][0] << " | " << traders_statuses[trader_id][1] << std::endl;
        total_result += traders_statuses[trader_id][0];
    }

    double max_result = 0.0;
    int max_result_trader = -1;
    double min_result = 999999.0;
    int min_result_trader = -1;

    double max_com = 0.0;
    int max_com_trader = -1;
    double min_com = 999999.0;
    int min_com_trader = -1;


    for (int trader_id = 0; trader_id < 3; trader_id++){
        if (traders_statuses[trader_id][0] > max_result) {
            max_result_trader = trader_id;
            max_result = traders_statuses[trader_id][0];
        }
        if (traders_statuses[trader_id][0] < min_result) {
            min_result_trader = trader_id;
            min_result = traders_statuses[trader_id][0];
        }


        if (traders_statuses[trader_id][1] > max_com) {
            max_com_trader = trader_id;
            max_com = traders_statuses[trader_id][1];
        }
        if (traders_statuses[trader_id][1] < min_com) {
            min_com_trader = trader_id;
            min_com = traders_statuses[trader_id][1];
        }
    }
    std::cout << "1)" << std::endl;
    std::cout << "Выручил больше всего денег (" << max_result <<") :" << std::endl;
    std::cout << max_result_trader + 1 << std::endl;
    std::cout << "Выручил меньше всего денег (" << min_result <<") :" << std::endl;
    std::cout << min_result_trader + 1 << std::endl;

    std::cout << "2)" << std::endl;
    std::cout << "Самые большие комиссионные (" << max_com <<") :" << std::endl;
    std::cout << max_com_trader + 1 << std::endl;
    std::cout << "Меньше всего комиссионных (" << min_com <<") :" << std::endl;
    std::cout << min_com_trader + 1 << std::endl;

    std::cout << "3) Прибыль :" << std::endl;
    std::cout << total_result << std::endl;

    std::cout << "4) Потрачено на комиссионные :" << std::endl;
    double com_sum = 0.0;
    for (int trader_id = 0; trader_id < 3; trader_id++){
        com_sum += traders_statuses[trader_id][1];
    }
    std::cout << com_sum << std::endl;

    std::cout << "5) Через руки продавцов прошло :" << std::endl;
    std::cout << com_sum + total_result << std::endl;


}