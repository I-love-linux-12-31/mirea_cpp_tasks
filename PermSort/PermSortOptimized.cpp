//
// Created by yaroslav_admin on 02.10.22.
//

#include <iostream>
#include <vector>

std::vector<int_fast32_t> ZERO_DATA = {};


void print_vector (std::vector<int_fast32_t> &data) {
    for (int_fast32_t i : data){
        std::cout << std::to_string((int)i) << " ";
    }
    std::cout << std::endl;

}


int_fast32_t pop_item(int_fast32_t index, std::vector<int_fast32_t> &data){
    int_fast32_t result = data[index];
    data.erase(data.begin() + index);
    return result;
}

bool is_sorted(std::vector<int_fast32_t> &data){
    for(int_fast32_t i = 0; i < data.size() - 1; i++){
        if (data[i + 1] < data[i]){
            return false;
        }
    }
    return true;
}


std::vector<int_fast32_t> PermSort (std::vector<int_fast32_t> &data, std::vector<int_fast32_t> variants){
    std::vector<int_fast32_t> temp_vector = data;
    if (variants.size() == 1){
        temp_vector.push_back(variants[0]);
        if (is_sorted(temp_vector)){
            return temp_vector;
        }
        return ZERO_DATA;
    }
    std::vector<int_fast32_t> result;
    std::vector<int_fast32_t> vr2;
    for (int_fast32_t i = 0; i < variants.size(); i++){
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

    std::vector<int_fast32_t> data = {3, 2, 5, -5, 8, 9, -11, 24, -37, 0};
    std::vector<int_fast32_t> sorted = PermSort(ZERO_DATA, data);
    print_vector(sorted);

    return 0;
}