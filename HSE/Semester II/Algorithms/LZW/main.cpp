#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;

std::vector<int> lzwEncoding(const std::string& input) {
    std::unordered_map<std::string, int> dictionary;
    std::vector<int> result;
    std::string current_string;
    std::string next;

    constexpr int kMaxCode = 128;

    int next_code = kMaxCode;
    for (int i = 0; i < kMaxCode; ++i) {
        dictionary[std::string(1, static_cast<char>(i))] = i;
    }

    for (char letter : input) {
        next = current_string + letter;
        if (dictionary.find(next) != dictionary.end()) {
            current_string = next;
        } else {
            result.emplace_back(dictionary[current_string]);
            dictionary[next] = next_code++;
            current_string = std::string(1, letter);
        }
        next.clear();
    }

    if (!current_string.empty()) {
        result.emplace_back(dictionary[current_string]);
    }

    return result;
}

std::string lzwDecoding(const std::vector<int>& data) {
    int max_code = 128;

    std::vector<std::string> dictionary(max_code);
    for (int i = 0; i < max_code; ++i) {
        dictionary[i] = std::string(1, static_cast<char>(i));
    }

    std::string current = dictionary[data[0]];
    std::string output = current;

    for (size_t i = 1; i < data.size(); ++i) {
        int code = data[i];
        std::string entry;
        if (code < max_code) {
            entry = dictionary[code];
        } else if (code == max_code) {
            entry = current + current[0];
        }

        output += entry;
        dictionary.emplace_back(current + entry[0]);
        current = entry;
        max_code += 1;
    }

    return output;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //    std::string input;
    //    std::getline(cin, input);
    //
    //    std::vector<int> result = lzwEncoding(input);
    //
    //    cout << result.size() << '\n';
    //    for (int code : result) {
    //        cout << code << ' ';
    //    }
    //
    //    cout << '\n';
    //
    //    std::string decoded = lzwDecoding(result);
    //    cout << decoded;

    int size;
    cin >> size;
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    std::string decoded = lzwDecoding(data);
    cout << decoded;

    return 0;
}
