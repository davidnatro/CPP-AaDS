#include <iostream>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::vector;

void doubleVector(vector<int>& vec, int vector_size) {
    for (int i = 0; i < vector_size; ++i) {
        vec[i] *= 2;
    }
}

bool positiveDominate(const vector<int>& vec, int vector_size) {
    int count = 0;
    int half = vector_size / 2;
    for (int i = 0; i < vector_size; ++i) {
        if (vec[i] > 0) {
            ++count;
            if (count > half) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int vector_size;
    cin >> vector_size;

    vector<int> input_vector(vector_size);
    vector<int> result_vector(vector_size, 0);

    int operations = 0;

    int input;
    for (int i = 0; i < vector_size; ++i) {
        cin >> input;
        input_vector[i] = input;
    }
    cout.flush();

    if(positiveDominate(input_vector, vector_size)) {
        for (int i = 0; i < vector_size; ++i) {
            if (input_vector[i] > result_vector[i]) {
                ++result_vector[i];
                ++operations;
            }
        }

    }

    return 0;
}
