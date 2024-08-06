#include "best-time-to-buy-and-sell-stock.hpp"

int BestTimeToBuyAndSellStock::maxProfit(std::vector<int>& prices) const {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        const int daily_profit = prices[i] - prices[i - 1];
        if (daily_profit > profit) {
            profit = daily_profit;
        }

        if (daily_profit > 0) {
            prices[i] = prices[i - 1];
        }
    }
    return profit;
}