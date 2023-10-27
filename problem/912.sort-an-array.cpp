/*
 * @lc app=leetcode.cn id=912 lang=cpp
 * @lcpr version=30102
 *
 * [912] 排序数组
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,2,0,0]\n
// @lcpr case=end

 */
