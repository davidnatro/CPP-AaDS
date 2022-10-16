#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
using std::gcd;
using std::vector;

vector<int> factorize(uint64_t input) {
    vector<int> result;
    for (int i = 2; i * i <= input; ++i) {
        while (input % i == 0) {
            result.emplace_back(i);
            input /= i;
        }
    }
    if (input != 1) {
        result.emplace_back(input);
    }

    return result;
}

int main() {
    uint64_t a, b;
    cin >> a >> b;

    uint64_t gcd_start = gcd(a, b);
    uint64_t gcd_end;

    vector<int> a_f = factorize(a);
    vector<int> b_f = factorize(b);

    for (const int& element : b_f) {
        gcd_end = gcd(a * element, b);
        if (gcd_end > gcd_start) {
            gcd_start = gcd_end;
        }
    }

    for (const int& element : a_f) {
        gcd_end = gcd(a, b * element);
        if (gcd_end > gcd_start) {
            gcd_start = gcd_end;
        }
    }

    cout << gcd_start;

    return 0;
}
