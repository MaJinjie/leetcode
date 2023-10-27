/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=30102
 *
 * [96] 不同的二叉搜索树
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  std::vector<int> dp;

public:
  Solution() {
    dp.resize(20);
    dp[0] = 1;
  }
  int numTrees(int n) {
    int &x = dp[n];
    if (x)
      return x;
    for (int i = 0; i <= n - 1; ++i) {
      x += numTrees(i) * numTrees(n - i - 1);
    }
    return x;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
