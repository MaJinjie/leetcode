/*
 * @lc app=leetcode.cn id=213 lang=cpp
 * @lcpr version=30102
 *
 * [213] 打家劫舍 II
 */

// @lcpr-template-start

#include "common.hpp"
#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  int _rob(std::vector<int> &nums, int start, int end) {
    int first, second, ans;
    first = nums[start], ans = second = max(first, nums[++start]);
    while (++start <= end) {
      ans = max(second, first + nums[start]);
      first = second;
      second = ans;
    }
    return ans;
  }

public:
  int rob(vector<int> &nums) {
    /*
    dp[i];
dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);

dp[0] , dp[1]
*/

    int n = nums.size();
    if (n <= 2)
      return *max_element(nums.cbegin(), nums.cend());
    return std::max(_rob(nums, 0, n - 2), _rob(nums, 1, n - 1));
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
