/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30102
 *
 * [76] 最小覆盖子串
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  string minWindow(string s, string t) {
    int cnt[256]{0};
    int diff = 0;
    for (char ch : t) {
      if (++cnt[ch] == 1)
        diff++;
    }
    int pos = -1;
    int len = INT_MAX;
    for (int left = 0, right = 0; right < s.size(); ++right) {
      if (--cnt[s[right]] == 0)
        diff--;

      while (diff == 0) {
        if (right - left + 1 < len) {
          pos = left;
          len = right - left + 1;
        }

        if (++cnt[s[left]] == 1)
          diff++;
        left++;
      }
    }
    return pos == -1 ? "" : s.substr(pos, len);
  }
};
// @lc code=end

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */
