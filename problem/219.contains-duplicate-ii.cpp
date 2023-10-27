/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30102
 *
 * [219] 存在重复元素 II
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    std::unordered_multiset<int> uset;
    int n = nums.size();
    for (int left = 0, right = 0; right < n; ++right) {
      if (uset.contains(nums[right]))
        return true;
      uset.insert(nums[right]);
      if (right - left >= k) {
        uset.erase(nums[left]);
        left++;
      }
    }
    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
