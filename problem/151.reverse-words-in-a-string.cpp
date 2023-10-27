/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30102
 *
 * [151] 反转字符串中的单词
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  string reverseWords(string s) {
    s += ' ';
    std::string_view sv(s);
    std::string res;
    while (sv.front() == ' ')
      sv.remove_prefix(1);

    int start, end;
    for (int i = sv.size() - 1; i >= 0; --i) {
      while (sv[i] == ' ')
        i--;
      end = i;
      while (i >= 0 and sv[i] != ' ')
        i--;
      start = i + 1;
      res += sv.substr(start, end - start + 1);
      if (i >= 0)
        res += ' ';
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
