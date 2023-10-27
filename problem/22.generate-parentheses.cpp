/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30102
 *
 * [22] 括号生成
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  template <typename _T> using vt = std::vector<_T>;
  template <size_t _N> using bits = std::bitset<_N>;
  vt<string> res;
  string path;
  int left_count;
  int check;
  void backtrace(int n) {
    if (path.size() == 2 * n) {
      res.push_back(path);
      return;
    }
    if (left_count < n) {
      left_count++;
      check++;
      path += '(';
      backtrace(n);
      path.pop_back();
      check--;
      left_count--;
    }
    if (check > 0) {
      check--;
      path += ')';
      backtrace(n);
      path.pop_back();
      check++;
    }
  }

public:
  vector<string> generateParenthesis(int n) {
    left_count = check = 0;
    backtrace(n);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
