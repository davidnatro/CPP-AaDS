#include <iostream>
#include <numeric>

using std::cin;
using std::cout;

int main() {
    uint64_t a, b;
    cin >> a >> b;

    const int prime = 3;

    if (a == 1) {
        cout << b;
        return 0;
    } else if (b == 1) {
        cout << a;
        return 0;
    }

    cout << std::max(std::gcd(a * prime, b), std::gcd(a, prime * b));

    return 0;
}
