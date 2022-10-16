#include <iostream>

using std::cin;
using std::cout;

// Идея
// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem#:~:text=Lagrange's%20four%2Dsquare%20theorem%2C%20also,additive%20basis%20of%20order%20four.&text=This%20theorem%20was%20proven%20by%20Joseph%20Louis%20Lagrange%20in%201770.

/*
 * Суть данного алгоритма заключается в полном переборе.
 * Нам нужна сумма четырех квадратов.
 * Пусть вводится число 4
 * Тогда мы запускаем 4 вложенных цикла, которые перебирают
 * всевозможные комбинации суммы квадратов.
 * 0 0 0 0
 * 0 0 0 1
 * 0 0 0 1
 * . . . .
 * 1 1 1 1
 */

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int input;
    cin >> input;

    for (int i = 0; i * i <= input; ++i) {
        if (i * i == input) {
            cout << i;
            return 0;
        }
        for (int j = i; j * j <= input; ++j) {
            if (i * i + j * j == input) {
                cout << i << " " << j;
                return 0;
            }
            for (int k = j; k * k <= input; ++k) {
                if (i * i + j * j + k * k == input) {
                    cout << i << " " << j << " " << k;
                    return 0;
                }
                for (int l = k; l * l <= input; ++l) {
                    if (i * i + j * j + k * k + l * l == input) {
                        cout << i << " " << j << " " << k << " " << l;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
