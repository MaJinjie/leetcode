/*
 * @lc app=leetcode.cn id=123 lang=cpp
 * @lcpr version=30102
 *
 * [123] 买卖股票的最佳时机 III
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
    hold1, sale1, hold, sale2
    hold1 = max(hold1, -prices[i]);
    sale1 = max(sale1, hold1 + prices[i]);
*/
    int hold1, hold2, sale1, sale2;
    hold1 = hold2 = -prices[0];
    sale1 = sale2 = 0;

    for (int i = 1; i < prices.size(); ++i) {
      sale2 = max(sale2, hold2 + prices[i]);
      hold2 = max(hold2, sale1 - prices[i]);
      sale1 = max(sale1, hold1 + prices[i]);
      hold1 = max(hold1, -prices[i]);
    }
    return sale2;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,3,5,0,0,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
