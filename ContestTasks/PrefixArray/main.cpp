#include <iostream>
#include <vector>

#include <fstream>
std::ifstream f_in("../input.txt");

using std::cin;
using std::cout;

void readData(std::vector<int>& vector, std::vector<int>& prefix_vector, int size) {
    for (int i = 0; i < size; ++i) {
        f_in >> vector[i];

        if (vector[i] == 0) {
            ++prefix_vector[i];
        }
        if (i > 0) {
            prefix_vector[i] += prefix_vector[i - 1];
        }
    }
}

int getZerosOnInterval(int left, int right, const std::vector<int>& prefix_vector) {
    if (left == 1) {
        return prefix_vector[right - 1];
    }
    
    return prefix_vector[right - 1] - prefix_vector[left - 2];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    f_in >> size;
    std::vector<int> vector(size);

    std::vector<int> prefix_vector(size, 0);

    readData(vector, prefix_vector, size);

    int operations;
    f_in >> operations;
    operations += 1;
    cout.flush();

    int left, right;
    while (--operations) {
        f_in >> left >> right;

        cout << getZerosOnInterval(left, right, prefix_vector) << " ";
    }

    return 0;
}