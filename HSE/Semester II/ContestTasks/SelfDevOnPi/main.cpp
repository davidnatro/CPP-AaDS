#include <iostream>
#include <vector>

using std::cin;
using std::cout;

uint16_t levenshtein(const std::string &first, const std::string &second) {
    std::vector<std::vector<uint16_t>> d(first.size() + 1,
                                         std::vector<uint16_t>(second.size() + 1, 0));

    for (size_t i = 0; i <= first.size(); ++i) {
        d[i][0] = i;
    }

    for (size_t i = 0; i <= second.size(); ++i) {
        d[0][i] = i;
    }

    for (size_t j = 1; j <= second.size(); ++j) {
        for (size_t i = 1; i <= first.size(); ++i) {
            if (first[i - 1] == second[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = std::min(d[i - 1][j], std::min(d[i][j - 1], d[i - 1][j - 1])) + 1;
            }
        }
    }

    return d[first.size()][second.size()];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int16_t commands_size;
    cin >> commands_size;

    std::vector<std::string> commands(commands_size);
    for (int i = 0; i < commands_size; ++i) {
        cin >> commands[i];
    }

    int16_t max_errors;
    cin >> max_errors;

    int16_t inputs_size;
    cin >> inputs_size;

    std::vector<std::string> inputs(inputs_size);
    for (int i = 0; i < inputs_size; ++i) {
        cin >> inputs[i];
    }

    for (const std::string &input : inputs) {
        int count = 0;
        for (const std::string &command : commands) {
            if (levenshtein(input, command) <= max_errors) {
                count += 1;
            }
        }
        cout << count << '\n';
    }

    return 0;
}
