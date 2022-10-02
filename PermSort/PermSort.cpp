//
// Created by yaroslav_admin on 01.10.22.
//

#include <iostream>
#include <vector>

std::vector<int> ZERO_DATA = {};


void print_vector (std::vector<int> &data) {
    for (int i : data){
        std::cout << i << " ";
    }
    std::cout << std::endl;

}


int pop_item(int index, std::vector<int> &data){
    int result = data[index];
    data.erase(data.begin() + index);
    return result;
}

bool is_sorted(std::vector<int> &data){
    for(unsigned int i = 0; i < data.size() - 1; i++){
        if (data[i + 1] < data[i]){
            return false;
        }
    }
    return true;
}


std::vector<int> PermSort (std::vector<int> &data, std::vector<int> variants){
    std::vector<int> temp_vector = data;
    if (variants.size() == 1){
        temp_vector.push_back(variants[0]);
        if (is_sorted(temp_vector)){
            return temp_vector;
        }
        return ZERO_DATA;
    }
    std::vector<int> result;
    std::vector<int> vr2;
    for (int i = 0; i < variants.size(); i++){
        temp_vector = data;
        vr2 = variants;
        temp_vector.push_back(pop_item(i, vr2));
        result = PermSort(temp_vector, vr2);
        if (result != ZERO_DATA){
            return result;
        }
    }

    return ZERO_DATA;
}


int main(){

    std::vector<int> data = {3, 2, 5, -5, 8, 9, -11, 24, -37, 0};
    std::vector<int> sorted = PermSort(ZERO_DATA, data);
    print_vector(sorted);

    return 0;
}