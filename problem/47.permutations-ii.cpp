/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30102
 *
 * [47] 全排列 II
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  template <typename _T> using vt = std::vector<_T>;
  vt<int> path;
  vt<vt<int>> res;
  std::bitset<10> bset;
  void backtrace(vt<int> &nums) {
    int n = nums.size();
    if (n == path.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (bset.test(i) or
          (i > 0 and !bset.test(i - 1)) and nums[i] == nums[i - 1])
        continue;
      bset.flip(i);
      path.push_back(nums[i]);
      backtrace(nums);
      path.pop_back();
      bset.flip(i);
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    backtrace(nums);

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
