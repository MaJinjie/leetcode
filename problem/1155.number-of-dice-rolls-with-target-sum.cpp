/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 * @lcpr version=30102
 *
 * [1155] 掷骰子等于目标和的方法数
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  static constexpr int MOD = 1e9 + 7;

public:
  // 这是一个排列问题，而不是一个组合问题
  int numRollsToTarget(int n, int k, int target) {
    /*
    dp[i][j] 表示前i个筛子得到和为j的组合数
    dp[i][j] = dp[i - 1][j - val] val-[1, k]
*/
    std::vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    // for (int i = 1; i <= n; ++i) {
    //   for (int j = 1; j <= target; ++j) {
    //     int &x = dp[i][j];
    //     for (int k1 = 1; k1 <= k; ++k1) {
    //       if (j >= k1)
    //         x = (x + dp[i - 1][j - k1]) % MOD;
    //     }
    //   }
    // }

    // 组合问题
    for (int k1 = 1; k1 <= k; ++k1) {
      for (int i = 1; i <= n; ++i) {
        for (int j = k1; j <= target; ++j) {
          dp[i][j] = (dp[i - 1][j - k1] + dp[i][j]) % MOD;
        }
      }
    }
    return dp[n][target];
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n3\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n7\n
// @lcpr case=end

// @lcpr case=start
// 30\n30\n500\n
// @lcpr case=end

 */
