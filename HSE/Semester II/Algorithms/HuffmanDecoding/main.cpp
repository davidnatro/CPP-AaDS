#include <iostream>
#include <map>

using std::cin;
using std::cout;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int unique_letters, coded_string_size;
    cin >> unique_letters >> coded_string_size;

    std::map<std::string, char> data;

    std::string letter;
    std::string code;
    for (int i = 0; i < unique_letters; ++i) {
        cin >> letter >> code;
        data[code] = letter[0];
    }

    std::string coded_string;
    cin >> coded_string;

    std::string result;
    code.clear();
    for (int i = 0; i <= coded_string_size; ++i) {
        if (data.find(code) != data.end()) {
            result += data[code];
            code.clear();
        }

        code += coded_string[i];
    }

    cout << result;

    return 0;
}
