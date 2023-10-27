/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30102
 *
 * [84] 柱状图中最大的矩形
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    heights.push_back(0);
    heights.insert(heights.begin(), 0);
    std::stack<int> st;

    int res = 0;
    int n = heights.size();
    for (int i, j = 0; j < n; ++j) {
      while (!st.empty() and heights[st.top()] > heights[j]) {
        int height = heights[st.top()];
        st.pop();
        i = st.top();
        res = max(res, height * (j - i - 1));
      }
      st.push(j);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
