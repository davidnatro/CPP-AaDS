#include <iostream>
#include <vector>

using std::cin;
using std::cout;

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_price = INT32_MAX;
        int max_profit = 0;
        // [7,1,5,3,6,4]
        for (size_t i = 0; i < prices.size(); ++i) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            }
        }

        return max_profit;
    }
};

int main() {
    Solution solution;
    std::vector<int> data{7, 1, 5, 3, 6, 4};

    cout << solution.maxProfit(data);

    return 0;
}
