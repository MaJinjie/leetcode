/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30102
 *
 * [216] 组合总和 III
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  std::vector<vector<int>> res;
  std::vector<int> path;
  int target;

  void backtrace(int start, int cursum, int k) {
    if (k == path.size() and cursum == this->target) {
      res.push_back(path);
      return;
    }
    for (int i = start; i <= 9; ++i) {
      if (cursum + i > this->target)
        break;
      path.push_back(i);
      backtrace(i + 1, cursum + i, k);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    this->target = n;
    backtrace(1, 0, k);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */
