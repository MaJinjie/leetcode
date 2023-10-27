/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30102
 *
 * [198] 打家劫舍
 */

// @lcpr-template-start

#include "common.hpp"
#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {
    int first, second, ans;
    const int n = nums.size();
    first = nums[0], second = nums[0];
    if (n >= 2)
      second = max(second, nums[1]);
    ans = second;
    for (int id = 0; int num : nums) {
      if (id++ >= 2) {
        ans = max(second, first + num);
        first = second;
        second = ans;
      }
    }

    return ans;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */
