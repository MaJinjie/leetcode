/*
 * @lc app=leetcode.cn id=1402 lang=cpp
 * @lcpr version=30102
 *
 * [1402] 做菜顺序
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int maxSatisfaction(vector<int> &satisfaction) {

    /*
    dp[i][j] 在前i道菜中，选择做j道菜所获得的最大系数
    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + val)
*/
    int n = satisfaction.size();
    int res = 0;
    sort(satisfaction.begin(), satisfaction.end());
    std::vector<vector<int>> dp(n + 1, std::vector<int>(n + 1, INT_MIN / 2));
    for (int i = 0; i <= n; ++i)
      dp[i][0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] =
            max(dp[i - 1][j], dp[i - 1][j - 1] + satisfaction[i - 1] * j);

        if (res < dp[i][j])
          res = dp[i][j];
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,-8,0,5,-9]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-4,-5]\n
// @lcpr case=end

 */
