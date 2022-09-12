//Lesson 5

#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
    std::fstream iofile("MyText.txt", std::ios::in | std::ios::out);

    if (!iofile)
    {
        std::cout << "Failed to open file !" << std::endl;
        exit(1);
    }

    char item;
    while (iofile.get(item)){
        if (item == ' ') {

                iofile.seekg(-1, std::ios::cur);
                iofile << '#';
                iofile.seekg(iofile.tellg(), std::ios::beg);

        }
    }
    return 0;
}