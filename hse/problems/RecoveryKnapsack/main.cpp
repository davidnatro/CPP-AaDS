#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;

class Item {
    int weight_;
    int value_;

public:
    Item() : weight_(0), value_(0) {
    }

    Item(int weight, int value) : weight_(weight), value_(value) {
    }

    int getWeight() const {
        return weight_;
    }

    void setWeight(int weight) {
        weight_ = weight;
    }

    int getValue() const {
        return value_;
    }

    void setValue(int value) {
        value_ = value;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int items_size, max_weight;
    cin >> items_size >> max_weight;
    std::vector<Item> items(items_size);

    int weight;
    for (int i = 0; i < items_size; ++i) {
        cin >> weight;
        items[i].setWeight(weight);
    }

    int value;
    for (int i = 0; i < items_size; ++i) {
        cin >> value;
        items[i].setValue(value);
    }

    std::vector<std::vector<int>> data(items_size + 1, std::vector<int>(max_weight + 1));
    for (int i = 1; i <= items_size; ++i) {
        for (int j = 1; j <= max_weight; ++j) {
            if (items[i - 1].getWeight() > j) {
                data[i][j] = data[i - 1][j];
            } else {
                data[i][j] = std::max(data[i - 1][j], data[i - 1][j - items[i - 1].getWeight()] +
                                                          items[i - 1].getValue());
            }
        }
    }

    int a = data[items_size][max_weight];
    std::cout << a << "\n";

    std::vector<Item> result;
    int i = items_size;
    int j = max_weight;
    while (i > 0 && j > 0) {
        if (data[i][j] != data[i - 1][j]) {
            result.push_back(items[i - 1]);
            j -= items[i - 1].getWeight();
        }

        i -= 1;
    }

    int b = 0;
    for (const auto &item : result) {
        b += item.getWeight();
    }
    std::cout << b << "\n";

    std::cout << result.size() << "\n";

    for (const auto &item : result) {
        std::cout << item.getWeight() << " ";
    }
    std::cout << "\n";

    for (const auto &item : result) {
        std::cout << item.getValue() << " ";
    }

    return 0;
}
