#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>

using std::cin;
using std::cout;

bool isPowerOfTwo(int n) {
    if (n == 0) {
        return false;
    }

    return (std::ceil(std::log2(n)) == std::floor(std::log2(n)));
}

std::string hamming(const std::string &bit_string) {
    std::vector<std::vector<char>> bits(1, std::vector<char>(1, '\0'));

    std::vector<int> power_of_two_indexes;

    int count = 0;
    int index = 0;
    for (size_t i = 1; i <= bit_string.size() + count; ++i) {
        if (isPowerOfTwo(i)) {
            bits[0].emplace_back('0');
            power_of_two_indexes.emplace_back(i);
            count += 1;
        } else {
            bits[0].emplace_back(bit_string[index]);
            index += 1;
        }
    }

    bits.resize(count + 1);
    for (int i = 1; i < bits.size(); ++i) {
        bits[i].resize(bits[0].size());
    }

    std::string binary_num;
    for (int j = 1; j <= bit_string.size() + count; ++j) {
        binary_num = std::bitset<32>(j).to_string();
        int row = 1;
        int end = 31;
        for (int i = 0; i < count; ++i) {
            bits[row][j] = binary_num[end];
            row += 1;
            end -= 1;
        }
    }

    index = 0;
    for (int i = 1; i < bits.size(); ++i) {
        int scalar = 0;
        for (int j = 0; j < bits[0].size(); ++j) {
            scalar += (static_cast<int>(bits[i][j]) * static_cast<int>(bits[0][j])) % 2;
        }

        bits[0][power_of_two_indexes[index]] = (scalar % 2 == 0) ? '0' : '1';
        index += 1;
    }

    std::string result;

    for (int i = 1; i < bits[0].size(); ++i) {
        result += bits[0][i];
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string bit_string;
    cin >> bit_string;

    cout << hamming(bit_string);

    return 0;
}
