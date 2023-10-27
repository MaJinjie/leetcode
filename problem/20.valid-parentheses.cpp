/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30102
 *
 * [20] 有效的括号
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  const unordered_map<char, char> umap = {{')', '('}, {']', '['}, {'}', '{'}};

public:
  bool isValid(string s) {
    std::stack<char> st;
    for (char ch : s) {
      switch (ch) {
      case ')':
      case ']':
      case '}':
        if (st.empty() or st.top() != umap.at(ch))
          return false;
        st.pop();
        break;
      default:
        st.push(ch);
      }
    }
    return st.empty();
  }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */
