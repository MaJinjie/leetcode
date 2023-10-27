/*
 * @lc app=leetcode.cn id=122 lang=cpp
 * @lcpr version=30102
 *
 * [122] 买卖股票的最佳时机 II
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
        hold, sale
        hold[i] = max(hold[i - 1], sale[i - 1] - prices[i])
        sale[i] = max(sale[i - 1], hold[i - 1] + prices[i])

        hold[0] = -prices[0];
        sale[0] = 0;
    */
    int hold, sale;
    hold = -prices[0], sale = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
      int tmp = hold;
      hold = max(hold, sale - prices[i]);
      sale = max(sale, tmp + prices[i]);
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
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
