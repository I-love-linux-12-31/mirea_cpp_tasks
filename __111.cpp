//
// Created by yaroslav_admin on 26.10.22.
//

#include <iostream>
#include <vector>


std::vector<int> data[3];

int total_operations = 0;


int sources_index = 0;
int temp_index = 1;
int head = 0;

int buffer;

bool is_done(){
    if (head == sources_index)
        return false;
    for (int i = 0; i < data[head].size() - 1; i++)
        if (data[head][i + 1] < data[head][i])
            return false;
    return true;
}


void print_data_raw(){
    std::cout << "0 : ";
    for (int i : data[0])
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "1 : ";
    for (int i : data[1])
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "2 : ";
    for (int i : data[2])
        std::cout << i << " ";
    std::cout << std::endl;
}

void print_data() {
    for (int block = 0; block < 3; block++) {
        std::cout << block << " : ";
        for (int i = 1; i < data[block].size() + 1; i++)
            std::cout << data[block][data[block].size() - i] << " ";
        std::cout << std::endl;
    }
}
void move_head(){
    if (data[head].size() > 1){
        std::cout << head + 1 << " => " << temp_index + 1 << " | ";
        buffer =  data[head][0];
        data[head].erase(data[head].begin());
        data[temp_index].push_back(buffer);

        std::cout << head + 1 << " => " << sources_index + 1 << " | ";
        buffer =  data[head][0];
        data[head].erase(data[head].begin());
        data[sources_index].push_back(buffer);

        std::cout << head + 1 << " => " << sources_index + 1 << " | ";
        buffer =  data[head][0];
        data[head].erase(data[head].begin());
        data[sources_index].push_back(buffer);
    }

}

void next_move(){
    if (head == sources_index){
        head = 2;
        std::cout << sources_index + 1 << " => " << temp_index + 1 << " | ";
        buffer =  data[sources_index][0];
        data[sources_index].erase(data[sources_index].begin());
        data[temp_index].push_back(buffer);

        std::cout << sources_index + 1 << " => " << head + 1 << " | ";
        buffer =  data[sources_index][0];
        data[sources_index].erase(data[sources_index].begin());
        data[head].push_back(buffer);

        std::cout << temp_index + 1 << " => " << head + 1 << " | ";
        buffer =  data[temp_index][0];
        data[temp_index].erase(data[temp_index].begin());
        data[head].push_back(buffer);
        std::swap(data[head][0], data[head][1]);
        total_operations += 3;
    }
    else {
        std::cout << sources_index + 1 << " => " << temp_index + 1 << " | ";
        buffer =  data[sources_index][0];
        data[sources_index].erase(data[sources_index].begin());
        data[temp_index].push_back(buffer);

        std::cout << sources_index + 1 << " => " << head + 1 << " | ";
        buffer =  data[sources_index][0];
        data[sources_index].erase(data[sources_index].begin());
        data[head].push_back(buffer);

        std::cout << temp_index + 1 << " => " << head + 1 << " | ";
        buffer =  data[temp_index][0];
        data[temp_index].erase(data[temp_index].begin());
        data[head].push_back(buffer);
        std::swap(data[head][0], data[head][1]);
        total_operations += 3;




    }

    std::cout << std::endl;

}


int main(){

    int n = 3;
    for (int i = 0; i < n; i++){
        data[0].push_back(i + 1);
    }

    print_data();
    int step = 1;
    while (!is_done()){
        std::cout << "Step :" << step << std::endl;
        next_move();
        step++;
        print_data();
    }
    std::cout << "Общее число перемещений: " << total_operations << std::endl;
}