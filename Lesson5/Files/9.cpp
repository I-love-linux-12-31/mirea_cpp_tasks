//lesson 5
#include <iostream>
#include <fstream>

#include <cstdio>  // sscanf requirements !!!
#include <cstdarg> // sscanf requirements !!!

#include <vector>


void load_data_from_file (std::string file_name, std::vector<int> &data){
    std::ifstream file_in(file_name);
    if (!file_in){
        std::cout << "File read error !" << std::endl;
        exit(1);
    }
    std::string buffer;
    int int_buffer;
    while (file_in) {
        getline(file_in, buffer);
        if (std::sscanf(buffer.c_str(), "%d", &int_buffer) == 1) {
            data.push_back(int_buffer);
        }
    }
}

void write_data (std::vector<int> &data) {
    std::ofstream out_file("file_C");
    if (!out_file){
        std::cout << "File creation error !" << std::endl;
        exit(1);
    }
    for (unsigned int j = 0; j < data.size(); j++){
        out_file << data[j] << " " << std::endl;
    }

    out_file.close();
}

int main() {
    std::vector<int> data;
    int temp;
    load_data_from_file("file_A", data);
    load_data_from_file("file_B", data);
    for (unsigned int i = 0; i < data.size(); i++){
        for (unsigned int j = 0; j < data.size() - 1; j++){
            if (data[j + 1] < data[j]){
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }

//    for (unsigned int j = 0; j < data.size(); j++){
//        std::cout << data[j] << " " << std::endl;
//    }
    write_data(data);


}
