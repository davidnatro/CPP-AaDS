#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;

class Item {
    int weight_;
    int value_;

public:
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

void greedyKnapsack(const int items_size, int max_weight, const std::vector<Item>& items) {
    int value_result = 0;
    int weight_result = 0;

    std::vector<int> indexes;

    for (int i = 0; i < items_size; ++i) {
        if (items[i].getWeight() <= max_weight) {
            value_result += items[i].getValue();
            max_weight -= items[i].getWeight();
            weight_result += items[i].getWeight();
            indexes.emplace_back(i);
        }
    }

    cout << value_result << "\n" << weight_result << "\n" << indexes.size() << "\n";

    for (size_t i = 0; i < indexes.size(); ++i) {
        cout << items[indexes[i]].getWeight() << " ";
    }

    cout << "\n";

    for (size_t i = 0; i < indexes.size(); ++i) {
        cout << items[indexes[i]].getValue() << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int items_size;
    int max_weight;

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

    std::sort(items.begin(), items.end(), [](const Item& lhs, const Item& rhs) {
        double lhs_ratio =
            static_cast<double>(lhs.getValue()) / static_cast<double>(lhs.getWeight());
        double rhs_ratio =
            static_cast<double>(rhs.getValue()) / static_cast<double>(rhs.getWeight());

        if (lhs_ratio - rhs_ratio == 0) {
            return lhs.getWeight() > rhs.getWeight();
        }

        return lhs_ratio > rhs_ratio;
    });

    greedyKnapsack(items_size, max_weight, items);

    return 0;
}
