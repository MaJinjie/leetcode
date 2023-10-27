/*
 * @lc app=leetcode.cn id=503 lang=cpp
 * @lcpr version=30102
 *
 * [503] 下一个更大元素 II
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    std::vector<int> res(n, -1);
    std::stack<int> st;
    for (int i = 0; i < n; ++i) {
      while (!st.empty() and nums[st.top()] < nums[i]) {
        res[st.top()] = nums[i];
        st.pop();
      }
      st.push(i);
    }

    for (int num : nums) {
      if (st.empty())
        break;
      while (!st.empty() and nums[st.top()] < num) {
        res[st.top()] = num;
        st.pop();
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,3]\n
// @lcpr case=end

 */
