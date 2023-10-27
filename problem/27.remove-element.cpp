/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30102
 *
 * [27] 移除元素
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int n = nums.size();
    int i, j;
    for (i = j = 0; j < n; ++j) {
      if (nums[j] != val) {
        nums[i++] = nums[j];
      }
    }
    return i;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n2\n
// @lcpr case=end

 */
