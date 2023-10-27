/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30102
 *
 * [40] 组合总和 II
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  template <typename _T> using vt = std::vector<_T>;
  template <size_t _N> using bits = std::bitset<_N>;
  int target;
  vt<vt<int>> res;
  vt<int> path;
  void backtrace(vt<int> &nums, int start, int cursum) {
    if (cursum == this->target) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      if (cursum + nums[i] > this->target)
        break;
      if (i > start and nums[i] == nums[i - 1])
        continue;
      path.push_back(nums[i]);
      backtrace(nums, i + 1, cursum + nums[i]);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    int n = candidates.size();
    this->target = target;
    sort(candidates.begin(), candidates.end());
    backtrace(candidates, 0, 0);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8,\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5,\n
// @lcpr case=end

 */
