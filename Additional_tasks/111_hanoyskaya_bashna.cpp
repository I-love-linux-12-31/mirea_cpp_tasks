//
// Created by yaroslav_admin on 26.10.22.
//

#include "../cli_data_reader.h++"
#include <iostream>

int moves = 0;

void hanoi(int quantity, int from, int to, int buf_peg)
//quantity-число колец, from-начальное положение колец(1-3),to-конечное положение колец(1-3)
//buf_peg - промежуточный колышек(1-3)
{
    if (quantity != 0)
    {
        hanoi(quantity-1, from, buf_peg, to);
        std::cout << from << " => " << to << " | ";
        moves += 1;
        hanoi(quantity-1, buf_peg, to, from);
    }
}

int main()
{
    int start_peg = 1, destination_peg = 3, buffer_peg = 2, rings_quantity;
    std::cout << "Введите количество колец:" << std::endl;
    rings_quantity = get_int_more_0_from_user();
    hanoi(rings_quantity, start_peg, destination_peg, buffer_peg);
    std::cout << std::endl << "Общее число перемещений: " << moves << std::endl;
    return 0;
}