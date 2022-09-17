#include <iostream>
#include <cmath>

int customPow(int num, int pow) {
    int val = num;

    for (int i = 1; i < pow; ++i) {
        num *= val;
    }

    return num;
}

int countDigits(uint64_t number) {
    int count = 1;
    while (number /= 10) {
        ++count;
    }
    return count;
}

void splitNumber(uint64_t number, int split_at, uint64_t& a_out, uint64_t& b_out) {
    int split = customPow(10, split_at);

    a_out = floor(number / split);
    b_out = number % split;
}

uint64_t karatsuba(uint64_t x, uint64_t y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int length = std::min(countDigits(x), countDigits(y));
    int split_length = ceil(static_cast<double>(length) / 2);

    uint64_t a, b, c, d;
    splitNumber(x, split_length, a, b);
    splitNumber(y, split_length, c, d);

    uint64_t ac = karatsuba(a, c);
    uint64_t bd = karatsuba(b, d);
    uint64_t ad_bc = karatsuba(a + b, c + d) - ac - bd;

    return ac * static_cast<uint64_t>(customPow(10, length)) +
           ad_bc * static_cast<uint64_t>(customPow(10, split_length)) + bd;
}

// int main() {
//     uint64_t x, y;
//     std::cin >> x >> y;
//     std::cout << karatsuba(x, y);
//
//     return 0;
// }

#include <fstream>
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

// int main() {
//     std::string x, y;
//     cin >> x >> y;
//
//     uint64_t result = 0;
//
//     uint64_t temp_res;
//
//     uint64_t y_pow;
//     uint64_t x_pow = 0;
//
//     for (int i = x.size() - 1; i >= 0; --i) {
//         uint64_t v_ume = 0;
//         y_pow = 0;
//         for (int j = y.size() - 1; j >= 0; --j) {
//             v_ume *= pow(10, y_pow);
//
//             temp_res =
//                 (static_cast<int>((y[j] - '0')) * static_cast<int>((x[i] - '0')) *
//                      static_cast<uint64_t>(pow(10, y_pow)) * static_cast<uint64_t>(pow(10,
//                      x_pow)) +
//                  v_ume);
//             if (temp_res >= 10) {
//                 v_ume = static_cast<uint64_t>(
//                     floor(temp_res / static_cast<uint64_t>((pow(10, y_pow + 1)))));
//                 temp_res %= static_cast<uint64_t>(pow(10, y_pow + 1));
//             }
//             result += temp_res;
//             ++y_pow;
//             if (j == 0) {
//                 result += v_ume * static_cast<uint64_t>(pow(10, y_pow));
//             }
//         }
//         ++x_pow;
//     }
//
//     cout << result;
//
//     return 0;
// }

void mult(std::string x, std::string y) {
    uint64_t result = 0;

    uint64_t temp_res;

    uint64_t y_pow;
    uint64_t x_pow = 0;

    for (int i = x.size() - 1; i >= 0; --i) {
        uint64_t v_ume = 0;
        y_pow = 0;
        for (int j = y.size() - 1; j >= 0; --j) {
            v_ume *= pow(10, y_pow);

            temp_res =
                (static_cast<int>((y[j] - '0')) * static_cast<int>((x[i] - '0')) *
                     static_cast<uint64_t>(pow(10, y_pow)) * static_cast<uint64_t>(pow(10, x_pow)) +
                 v_ume);
            if (temp_res >= 10) {
                v_ume = static_cast<uint64_t>(
                    floor(temp_res / static_cast<uint64_t>((pow(10, y_pow + 1)))));
                temp_res %= static_cast<uint64_t>(pow(10, y_pow + 1));
            }
            result += temp_res;
            ++y_pow;
            if (j == 0) {
                result += v_ume * static_cast<uint64_t>(pow(10, y_pow));
            }
        }
        ++x_pow;
    }

    cout << result << "\n";
}

#include <vector>
#include <iostream>

// void multiplication() {
//     std::string x, y;
//     cin >> x >> y;
//
//     int x_length = x.size();
//     int y_length = y.size();
//     std::vector<int> result(x_length + y_length, 0);
//
//     for (int i = 0; i < y_length; ++i) {
//         int v_ume = 0;
//         for (int j = 0; j < x_length; ++j) {
//             int xj = x[j] - '0';
//             int yi = y[i] - '0';
//             result[i + j - 1] += xj * yi + v_ume;
//             v_ume  = result[i + j - 1] / 10;
//             result[i + j - 1] %= 10;
//         }
//         result[i + y_length - 1] = v_ume;
//     }
//
//     for(int i : result) {
//         cout << i;
//     }
// }

#include <vector>
#include <iostream>

using std::cin;
using std::cout;

// Идея алгоритма взята отсюда: https://en.wikipedia.org/wiki/Multiplication_algorithm
int main() {
    std::string x, y;
    cin >> x >> y;

    int x_length = x.size();
    int y_length = y.size();

    if (x_length == 0 || y_length == 0) {
        cout << "0";
        return 0;
    }

    std::vector<int> result(x_length + y_length, 0);

    int index1 = 0;
    int index2;

    for (int i = x_length - 1; i >= 0; --i) {
        int v_ume = 0;
        int x_num = x[i] - '0';
        index2 = 0;
        for (int j = y_length - 1; j >= 0; --j) {
            int y_num = y[j] - '0';
            int temp_res = x_num * y_num + result[index1 + index2] + v_ume;

            v_ume = temp_res / 10;
            result[index1 + index2] = temp_res % 10;

            ++index2;
        }

        if (v_ume > 0) {
            result[index1 + index2] += v_ume;
        }
        ++index1;
    }

    int index = result.size() - 1;
    while (index >= 0 && result[index] == 0) {
        --index;
        if (index == -1) {
            cout << "0";
            return 0;
        }
    }

    while (index >= 0) {
        cout << result[index];
        --index;
    }

    return 0;
}

// int main() {
//     const std::string zero_hundred = "../zero_hundred.txt";
//     const std::string input = "../input.txt";
//
//     std::ifstream f_in(input);
//
//     if (!f_in.is_open()) {
//         cout << "Cannot open the file."
//              << "\n";
//         return 0;
//     }
//
//     uint64_t num, num2;
//     while (f_in >> num) {
//         f_in >> num2;
//         uint64_t karatsuba_result = karatsuba(num, num2);
//         uint64_t simple_result = static_cast<uint64_t>(num) * static_cast<uint64_t>(num2);
//         cout << num << " x " << num2 << " := " << karatsuba_result << " == " << simple_result
//              << " : " << std::boolalpha << (karatsuba_result == simple_result) << " : "
//              << (countDigits(karatsuba_result) == countDigits(simple_result)) << " : ";
//         if (karatsuba_result > simple_result) {
//             cout << "karatsuba"
//                  << "\n";
//         } else if (karatsuba_result < simple_result) {
//             cout << "simple"
//                  << "\n";
//         } else {
//             cout << "equal"
//                  << "\n";
//         }
//     }
//
//     return 0;
// }