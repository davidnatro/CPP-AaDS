#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>

using std::cin;
using std::cout;

bool isPowerOfTwo(const int n) {
    if (n == 0) {
        return false;
    }

    return (std::ceil(std::log2(n)) - std::floor(std::log2(n))) == 0;
}

std::string hammingDecode(const std::string &hamming_code) {
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
        binary_num = std::bitset<32>(j).to_string();

        int row = 1;
        int end = 31;

        for (int i = 0; i < count; ++i) {
            bits[row][j] = binary_num[end];

            row += 1;
            end -= 1;
        }
    }

    std::vector<char> syndromes(count);
    for (size_t i = 1; i < bits.size(); ++i) {
        int scalar = 0;
        for (size_t j = 1; j < bits[0].size(); ++j) {
            scalar += ((bits[i][j] == '0' ? 0 : 1) * (bits[0][j] == '0' ? 0 : 1));
        }

        syndromes[i - 1] = (scalar % 2 == 0) ? '0' : '1';
    }

    std::string syndromes_string;
    bool is_correct = true;
    for (int i = syndromes.size() - 1; i >= 0; --i) {
        if (syndromes[i] != '0') {
            is_correct = false;
        }

        syndromes_string.push_back(syndromes[i]);
    }

    if (!is_correct) {
        int error_position = std::stoi(syndromes_string, nullptr, 2);
        if (error_position == 0) {
            error_position = 1;
        }

        if (error_position > 0 && error_position < bits[0].size()) {
            bits[0][error_position] = (bits[0][error_position] == '0') ? '1' : '0';
        }
    }

    std::string result;
    for (size_t i = 1; i < bits[0].size(); ++i) {
        if (!isPowerOfTwo(i)) {
            result.push_back(bits[0][i]);
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string hamming_code;
    cin >> hamming_code;

    cout << hammingDecode(hamming_code);

    return 0;
}
