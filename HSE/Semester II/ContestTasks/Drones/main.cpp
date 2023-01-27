#include <iostream>
#include <vector>

using std::cin;
using std::cout;

std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>>::iterator &begin,
                                       std::vector<std::pair<int, int>>::iterator &middle,
                                       std::vector<std::pair<int, int>>::iterator &end) {
    std::vector<std::pair<int, int>> vector;
    std::vector<std::pair<int, int>>::iterator i = begin;
    std::vector<std::pair<int, int>>::iterator j = middle;
    while (i != middle && j != end) {
        if (i->second >= j->second) {
            vector.push_back(*i++);
        } else {
            vector.push_back(*j++);
        }
    }

    while (i != middle) {
        vector.push_back(*i++);
    }

    while (j != end) {
        vector.push_back(*j++);
    }

    return vector;
}

void mergeSort(std::vector<std::pair<int, int>>::iterator begin,
               std::vector<std::pair<int, int>>::iterator end) {
    auto distance = end - begin;
    if (distance <= 1) {
        return;
    }

    std::vector<std::pair<int, int>>::iterator middle = begin + distance / 2;

    mergeSort(begin, middle);
    mergeSort(middle, end);

    std::vector<std::pair<int, int>> vector = merge(begin, middle, end);

    int index = 0;
    for (std::vector<std::pair<int, int>>::iterator it = begin; it != end; ++it) {
        it->first = vector[index].first;
        it->second = vector[index].second;
        ++index;
    }
}
void print(const std::vector<std::pair<int, int>> &capacity) {
    for (const std::pair<int, int> pair : capacity) {
        cout << pair.first << "\t" << pair.second << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;
    std::vector<std::pair<int, int>> load_capacity(size);

    int id, capacity;
    for (int i = 0; i < size; ++i) {
        cin >> id >> capacity;
        load_capacity[i] = std::make_pair(id, capacity);
    }

    mergeSort(load_capacity.begin(), load_capacity.end());

    print(load_capacity);

    return 0;
}
