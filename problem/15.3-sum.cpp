/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30102
 *
 * [15] 三数之和
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    std::vector<std::vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      int target = 0 - nums[i];
      if (i > 0 and nums[i] == nums[i - 1])
        continue;
      if (nums[i + 1] + nums[i + 2] > target)
        continue;
      if (nums[n - 1] + nums[n - 2] < target)
        continue;
      for (int left = i + 1, right = n - 1; left < right;) {
        int twosum = nums[left] + nums[right];
        if (twosum < target)
          left++;
        else if (twosum > target)
          right--;
        else {
          res.push_back({nums[i], nums[left], nums[right]});
          do
            left++;
          while (left < right and nums[left] == nums[left - 1]);
          right--;
        }
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
