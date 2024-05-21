#include "best-time-to-buy-and-sell-stock-with-transaction-fee.hpp"

int BestTimeToBuyAndSellStockWithTransactionFee::maxProfit(const std::vector<int> &prices,
                                                           const int fee) const {
  int hold = -prices[0];
  int cash = 0;

  for (int i = 1; i < prices.size(); ++i) {
    hold = std::max(hold, cash - prices[i]);
    cash = std::max(cash, hold + prices[i] - fee);
  }

  return cash;
}
