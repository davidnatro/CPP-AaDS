#include "StringGenerator.h"

std::ofstream f_out("../file.txt");
std::ofstream f_out_output("../input.txt");
std::string str = "AAAAAAAAAA";
auto hash = std::hash<std::string>{}(str);

void StringGenerator::printAllKLength(char *set, int k, int n) {
    printAllKLengthRec(set, "", n, k);
}

void StringGenerator::printAllKLengthRec(char *set, std::string prefix, int n, int k) {
    if (k == 0) {
        if (count <= 1000) {
            //std::cout << prefix << "\n";
            if (std::hash<std::string>{}(prefix) == hash) {
                f_out_output << prefix << "\n";
                std::cout << prefix << "\n";
                count += 1;
            }
        }

        return;
    }

    // One by one add all characters
    // from set and recursively
    // call for k equals to k-1
    for (int i = 0; i < n; i++) {
        std::string newPrefix;

        // Next character of input added
        newPrefix = prefix + set[i];

        // k is decreased, because
        // we have added a new character
        printAllKLengthRec(set, newPrefix, n, k - 1);
    }
}