// Lesson 5
#include <iostream>
#include <vector>
#include "../cli_data_reader.h++"

std::vector<std::vector<int>> get_variants(std::vector<std::vector<int>> data, std::vector<int> variants, int level){

    std::vector<std::vector<int>> result;
    std::vector<int> variants_temp;
    if (variants.empty())
        return data;

    for (int v_index = 0 ; v_index < variants.size(); v_index++){
        variants_temp = variants;
        int current_vr = variants_temp[v_index];
        variants_temp.erase(variants_temp.begin() + v_index);
        std::vector<std::vector<int>> data_temp;
            data_temp = data;
            for (int line_id = 0; line_id < data_temp.size(); line_id++){
                data_temp[line_id].push_back(current_vr);
            }
            if (data.empty()){
                data_temp.push_back({current_vr});
            }


            for (auto line : get_variants(data_temp, variants_temp, level + 1)){

                result.push_back(line);
            }

        //}
    }
    return result;
}


bool is_correct(std::vector<int> _line){
    for (int i = 0; i < _line.size(); i++){
        if (i == _line[i])
            return true;
    }
    return false;

}


int get_target_combinations_count ( std::vector<std::vector<int>> _data){
    int count = 0;
    for (auto _line : _data){
        if (is_correct(_line))
            count++;
    }
    return count;
}



int main () {
    std::cout << "Сколько шариков?" << std::endl;
    int n = get_int_more_0_from_user();
//    std::cout << "Нашлось " << factorial(n - 1)*n << " варианта(ов)" << std::endl;
//    std::cout << "Start" << std::endl;
    std::vector<int> numbers;
    for (int j = 0; j < n; j++){
        numbers.push_back(j);
    }

    auto res = get_variants({}, numbers, 0);
    std::cout << "Нашлось " << get_target_combinations_count(res) << " варианта(ов) из " << res.size() << std::endl;

}