/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30102
 *
 * [72] 编辑距离
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    // dp[i][j] [0...i] 转换为 [0...j] 所需要最少操作数
    // dp[n1 + 1] [n2 + 1]
    /*
        s1[i] == s2[j] :dp[i][j] = dp[i - 1][j - 1];
        s1[i] != s2[j] : dp[i][j]
            1. dp[i][j - 1] + 1
            2. dp[i - 1][j] + 1
            3. dp[i - 1][j - 1] + 1

        dp[0][0...j] dp[0...i][0]
*/
    int n1 = word1.size(), n2 = word2.size();

    int dp[n1 + 1][n2 + 1];

    for (int j = 0; j <= n2; ++j) {
      dp[0][j] = j;
    }
    for (int i = 0; i <= n1; ++i) {
      dp[i][0] = i;
    }

    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        dp[i][j] = dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]);
        dp[i][j] = min(dp[i][j], min(dp[i][j - 1], dp[i - 1][j]) + 1);
      }
    }

    return dp[n1][n2];
  }
};
// @lc code=end

/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */
