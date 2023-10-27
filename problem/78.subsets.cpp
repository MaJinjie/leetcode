/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30102
 *
 * [78] 子集
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
  void backtrace(std::vector<int> &nums, int start) {
    int n = nums.size();
    res.push_back(path);
    if (start == n)
      return;
    for (int i = start; i < n; ++i) {
      path.push_back(nums[i]);
      backtrace(nums, i + 1);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    backtrace(nums, 0);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
