#include "integer-to-english-words.hpp"

IntegerToEnglishWords::IntegerToEnglishWords() {
    mappings_[0] = "Zero";
    mappings_[1] = "One";
    mappings_[2] = "Two";
    mappings_[3] = "Three";
    mappings_[4] = "Four";
    mappings_[5] = "Five";
    mappings_[6] = "Six";
    mappings_[7] = "Seven";
    mappings_[8] = "Eight";
    mappings_[9] = "Nine";
    mappings_[10] = "Ten";
    mappings_[11] = "Eleven";
    mappings_[12] = "Twelve";
    mappings_[13] = "Thirteen";
    mappings_[14] = "Fourteen";
    mappings_[15] = "Fifteen";
    mappings_[16] = "Sixteen";
    mappings_[17] = "Seventeen";
    mappings_[18] = "Eighteen";
    mappings_[19] = "Nineteen";
    mappings_[20] = "Twenty";
    mappings_[30] = "Thirty";
    mappings_[40] = "Forty";
    mappings_[50] = "Fivty";
    mappings_[60] = "Sixty";
    mappings_[70] = "Seventy";
    mappings_[80] = "Eighty";
    mappings_[90] = "Ninety";
    mappings_[100] = "Hundred";
    mappings_[1000] = "Thousand";
    mappings_[1000000] = "Million";
    mappings_[1000000000] = "Billion";
}

std::string IntegerToEnglishWords::numberToWords(int num) {
    if (num == 0) {
        return mappings_[num];
    }

    int iteration = 1;
    std::string result;
    while (num > 0) {
        std::string part_result;
        if (num % 1000 != 0) {
            int part = num % 1000;

            if (part >= 100) {
                part_result += mappings_[part / 100] + " Hundred ";
                part %= 100;
            }

            if (part >= 20) {
                part_result += mappings_[part - (part % 10)] + " ";
                part %= 10;
            }

            if (part > 0) {
                part_result += mappings_[part] + " ";
            }

            part_result += (iteration > 1) ? mappings_[iteration] : " ";
            result = part_result + " " + result;
        }

        num /= 1000;
        if (iteration < 1000000000) {
            iteration *= 1000;
        }
    }

    int end_index = result.size() - 1;
    while (end_index >= 0 && result[end_index] == ' ') {
        end_index -= 1;
    }

    return result.substr(0, end_index + 1);
}