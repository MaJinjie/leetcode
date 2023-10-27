/*
 * @lc app=leetcode.cn id=85 lang=cpp
 * @lcpr version=30102
 *
 * [85] 最大矩形
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  int f(std::vector<int> &heights) {
    int n = heights.size();
    std::stack<int> st;
    int res = 0;
    for (int j = 0; j < n; ++j) {
      while (!st.empty() and heights[st.top()] > heights[j]) {
        int height = heights[st.top()];
        st.pop();
        int i = st.top() + 1;
        res = max(res, height * (j - i));
      }
      st.push(j);
    }
    return res;
  }

public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int r = matrix.size(), c = matrix[0].size();
    std::vector<vector<int>> heights(r, std::vector<int>(c + 2));
    for (int j = 1; j <= c; ++j) {
      int count = 0;
      for (int i = 0; i < r; ++i) {
        if (matrix[i][j - 1] == '1')
          count++;
        else
          count = 0;
        heights[i][j] = count;
      }
    }
    int res = 0;
    for (int i = 0; i < r; ++i)
      res = max(res, f(heights[i]));
    return res;
  }
};
/*
 class Solution {
 public:
   int maximalRectangle(vector<vector<char>> &matrix) {
     int r = matrix.size(), c = matrix[0].size();
     std::vector<vector<int>> presums(r, std::vector<int>(1 + c, 0));
     for (int i = 0; i < r; ++i) {
       auto &presum = presums[i];
       auto &nums = matrix[i];
       for (int j = 1; j <= c; ++j)
         presum[j] = presum[j - 1] + (nums[j - 1] == '1');
     }
     int startj, endj;
     int res = 0;
     auto check = [&presums, &startj, &endj](int i) {
       return presums[i][endj + 1] - presums[i][startj] == endj - startj + 1;
     };
     for (startj = 0; startj < c; ++startj) {
       for (endj = startj; endj < c; ++endj) {
         int maxlen = 0;
         int curlen = 0;
         for (int i = 0; i < r; ++i) {
           if (!check(i))
             curlen = -1;
           maxlen = max(maxlen, ++curlen);
         }
         res = max(res, maxlen * (endj - startj + 1));
       }
     }
     return res;
   }
 };
*/
// @lc code=end

/*
// @lcpr case=start
//
[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","0"]]\n
// @lcpr case=end

 */
