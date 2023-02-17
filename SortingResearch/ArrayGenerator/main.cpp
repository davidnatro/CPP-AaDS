#include <fstream>
#include <iostream>
#include <vector>

int randomNumber(const int min, const int max) {
    return std::rand() % (max - min + 1) + min;
}

int main() {
    std::ofstream f_out("../arrays.txt");

    srand(time(nullptr));

    std::vector<int> data;
    for (int i = 50; i <= 300; i += 50) {


    }

    for (int i = 100; i <= 4100; i += 100) {
    }


    return 0;
}
