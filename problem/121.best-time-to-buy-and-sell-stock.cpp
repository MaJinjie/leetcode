/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30102
 *
 * [121] 买卖股票的最佳时机
 */

// @lcpr-template-start

#include "common.hpp"
#include <format>
#include <string>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    /*
        hold sale
        hold[i] = hold[i - 1], -prices[i];
        sale[i] = sale[i - 1], hold[i - 1] + prices[i];
    */
    int hold, sale;
    hold = -prices[0], sale = 0;
    for (int i = 1; i < prices.size(); ++i) {
      sale = max(sale, hold + prices[i]);
      hold = max(hold, -prices[i]);
    }
    return sale;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
