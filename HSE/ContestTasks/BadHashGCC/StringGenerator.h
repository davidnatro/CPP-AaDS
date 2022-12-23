#ifndef BADHASHGCC_STRINGGENERATOR_H
#define BADHASHGCC_STRINGGENERATOR_H

#include <iostream>
#include <fstream>
#include <functional>

class StringGenerator {
    int count = 0;

public:
    void printAllKLength(char set[], int k, int n);

    void printAllKLengthRec(char set[], std::string prefix, int n, int k);
};

#endif  // BADHASHGCC_STRINGGENERATOR_H
