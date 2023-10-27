/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30102
 *
 * [39] 组合总和
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  template <typename _T> using vt = std::vector<_T>;
  template <size_t _N> using bs = std::bitset<_N>;
  vt<int> path;
  vt<vt<int>> res;
  int target;
  void backtrace(vt<int> &nums, int start, int cursum) {
    if (cursum == this->target) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
      if (cursum + nums[i] > this->target)
        break;
      path.push_back(nums[i]);
      backtrace(nums, i, cursum + nums[i]);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->target = target;
    backtrace(candidates, 0, 0);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
