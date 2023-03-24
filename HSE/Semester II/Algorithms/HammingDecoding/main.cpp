#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

bool isPowerOfTwo(int n) {
    if (n == 0) {
        return false;
    }

    return (std::ceil(std::log2(n)) == std::floor(std::log2(n)));
}

std::string decimalToBinary(int num, int size) {
    std::string str;
    while (num) {
        if (num & 1) {  // 1
            str += '1';
        } else {  // 0
            str += '0';
        }
        num >>= 1;
    }

    while (str.size() < size) {
        str += '0';
    }

    return str;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string hamming_code;
    cin >> hamming_code;

    std::vector<std::vector<char>> bits(1, std::vector<char>(hamming_code.size() + 1));

    int count = 0;
    for (size_t i = 1; i < bits[0].size(); ++i) {
        if (isPowerOfTwo(i)) {
            count += 1;
        }

        bits[0][i] = hamming_code[i - 1];
    }

    bits.resize(count + 1);
    for (size_t i = 1; i < bits.size(); ++i) {
        bits[i].resize(bits[0].size());
    }

    std::string binary_num;
    for (size_t j = 1; j < bits[0].size(); ++j) {
        binary_num = decimalToBinary(j, count);
        int row = 1;
        for (size_t i = 0; i < binary_num.size(); ++i) {
            bits[row][j] = binary_num[i];
            row += 1;
        }
    }

    std::vector<char> syndromes(count);
    int index = 0;
    for (size_t i = 1; i < bits.size(); ++i) {
        int scalar = 0;
        for (size_t j = 1; j < bits[0].size(); ++j) {
            scalar += static_cast<int>(bits[i][j]) * static_cast<int>(bits[0][j]) % 2;
        }

        syndromes[index] = (scalar % 2 == 0) ? '0' : '1';
        index += 1;
    }

    std::string syndromes_string;
    bool is_correct = true;
    for (const char syndrome : syndromes) {
        if (syndrome != '0') {
            is_correct = false;
        }

        syndromes_string.push_back(syndrome);
    }

    if (!is_correct) {
        std::reverse(syndromes_string.begin(), syndromes_string.end());
        int error_position = std::stoi(syndromes_string, nullptr, 2);
        bits[0][error_position] = (bits[0][error_position] == '0') ? '1' : '0';
    }

    std::string result;
    for (size_t i = 1; i < bits[0].size(); ++i) {
        if (!isPowerOfTwo(i)) {
            result.push_back(bits[0][i]);
        }
    }

    cout << result << "\n";

    return 0;
}
