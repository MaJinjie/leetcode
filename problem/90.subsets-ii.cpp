/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30102
 *
 * [90] 子集 II
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  typedef std::vector<int> vt;
  vt path;
  std::vector<vt> res;

  void backtrace(vt &nums, int start) {
    int n = nums.size();
    res.push_back(path);
    if (start == n)
      return;
    for (int i = start; i < n; ++i) {
      if (i > start and nums[i] == nums[i - 1])
        continue;
      path.push_back(nums[i]);
      backtrace(nums, i + 1);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    backtrace(nums, 0);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
