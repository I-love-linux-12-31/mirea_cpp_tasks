//
// Created by yaroslav_admin on 16.11.22.
//
#include <iostream>
#include <map>
#include <vector>

//  1	3	5	7	9	11	13	15	17	19	21	23	25	27	29	31	33	35
//  2	4	6	8	10	12	14	16	18	20	22	24	26	28	30	32	34	36
//
//  53  54	51	52	49	50	47	48	45	46	43	44	41	42	39	40	37	38

const unsigned int PLACES_COUNT = 54;

std::vector<unsigned int> statuses; // Сколько свободно мест (от 0 до 6, 6 - купе свободно)
std::map<unsigned int, unsigned int> links; // Словарь Место - Номер купе.


void init(){
    for (unsigned int i = 0; i < PLACES_COUNT / 6; i++){
        //std::cout << "Generating for " << i << std::endl;
        statuses.push_back(0);
        for (unsigned int j : {4 * i + 1, 4 * i + 2, 4 * i + 3, 4 * i + 4, PLACES_COUNT - i*2 - 1, PLACES_COUNT - i*2}){
            //std::cout << " * Added : " << j << std::endl;
            links[j] = i;
        }
    }


}


int main(){
    init();
    unsigned int buffer, n;
    std::cin >> n;
    for (int i = 0; i < n; i++){
        //std::cout << ">>";
        std::cin >> buffer;
        if (links.find(buffer) != links.end()) { // Проверка валидности ключа
            statuses[links[buffer]] += 1;
            links.erase(buffer);
        }
    }

    unsigned int result = 0;
    unsigned int now = 0;
    for (unsigned int i : statuses){
        if (i == 6){
            now += 1;
            if (now > result)
                result = now;
        }
        else {
            now = 0;
        }
    }
    std::cout << result << std::endl;
}

