#include "best-time-to-buy-and-sell-stock-ii.hpp"

int BestTimeToBuyAndSellStockII::maxProfit(const std::vector<int>& prices) const {
    int result = 0;
    for (int i = 1; i < prices.size(); ++i) {
        const int daily_profit = prices[i] - prices[i - 1];
        if (daily_profit > 0) {
            result += daily_profit;
        }
    }
    return result;
}