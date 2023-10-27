/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30102
 *
 * [58] 最后一个单词的长度
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int lengthOfLastWord(string s) {
    int res = 0;
    int i = s.size() - 1;
    while (s[i] == ' ')
      i--;
    while (i >= 0 and s[i] != ' ')
      i--, res++;
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */
