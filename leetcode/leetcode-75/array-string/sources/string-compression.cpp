#include "../headers/string-compression.h"

int StringCompression::compress(std::vector<char> &chars) {
    if (chars.size() <= 1) {
        return chars.size();
    }

    int size = 0;

    int count = 0;
    char symbol = chars[0];
    for (int i = 0; i <= chars.size(); ++i) {
        if (i < chars.size() && chars[i] == symbol) {
            count += 1;
        } else {
            chars[size] = symbol;
            size += 1;
            if (count > 9) {
                std::string count_str = std::to_string(count);
                for (const char count_symbol : count_str) {
                    chars[size] = count_symbol;
                    size += 1;
                }
            } else if (count > 1) {
                chars[size] = count + '0';
                size += 1;
            }

            if (i < chars.size()) {
                count = 0;
                symbol = chars[i];
                i -= 1;
            }
        }
    }

    chars.resize(size);
    return size;
}
