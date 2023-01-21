#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

double f(const double x) {
    return pow(x, 2) + sqrt(x);
}

double leftBorder(const double input) {
    double border = -1;

    while (f(border) > input) {
        border *= 2;
    }

    return border;
}

double rightBorder(const double input) {
    double border = 1;

    while (f(border) < input) {
        border *= 2;
    }

    return border;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double input;
    cin >> input;

    double left = leftBorder(input);
    double right = rightBorder(input);
    double mid = left + (right - left) / 2;

    const double eps = 0.0000001;

    while (right - left > eps) {
        if (f(mid) < input) {
            left = mid;
        } else if (f(mid) > input) {
            right = mid;
        }
        mid = left + (right - left) / 2;
    }

    cout << std::fixed << left + (right - left) / 2;

    return 0;
}
