// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=179 lang=cpp
 * @lcpr version=30102
 *
 * [179] 最大数
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    if (all_of(nums.begin(), nums.end(), [](int num) { return num == 0; }))
      return "0";
    auto comp = [](int num1, int num2) {
      auto s1 = to_string(num1);
      auto s2 = to_string(num2);
      return s1 + s2 > s2 + s1 ? true : false;
    };
    string res;
    sort(nums.begin(), nums.end(), comp);
    for (int num : nums)
      res += to_string(num);

    // auto it =
    //     find_if(res.begin(), res.end(), [](char ch) { return ch != '0'; });
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [10,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,30,34,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0]\n
// @lcpr case=end

 */
