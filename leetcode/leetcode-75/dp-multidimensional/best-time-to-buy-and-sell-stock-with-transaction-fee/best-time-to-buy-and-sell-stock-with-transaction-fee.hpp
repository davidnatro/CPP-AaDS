#ifndef LEETCODE_LEETCODE_75_DP_MULTIDIMENSIONAL_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_HPP_
#define LEETCODE_LEETCODE_75_DP_MULTIDIMENSIONAL_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_HPP_

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <vector>

class BestTimeToBuyAndSellStockWithTransactionFee {
 public:
  int maxProfit(const std::vector<int> &prices, const int fee) const;
};

#endif
