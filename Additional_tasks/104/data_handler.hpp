//
// Created by yaroslav_admin on 24.11.22.
//

#ifndef MIREA_CPP_TASKS_DATA_HANDLER_HPP
#define MIREA_CPP_TASKS_DATA_HANDLER_HPP

#include <yaml-cpp/yaml.h>
#include <fstream>
#include <vector>

YAML::Node data;


void load_data(){
    std::ifstream file_in("./data.yaml");
    data = YAML::Load(file_in);
    file_in.close();
}

void add_demo_value(){
    std::vector<int> t = {1, 2, 3, 4};
    data.push_back(t);
}

void save_data(){
    std::ofstream file_out("./data.yaml");
    file_out << YAML::Dump(data);
}

#endif //MIREA_CPP_TASKS_DATA_HANDLER_HPP
