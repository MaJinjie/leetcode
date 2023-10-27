/*
 * @lc app=leetcode.cn id=87 lang=cpp
 * @lcpr version=30102
 *
 * [87] 扰乱字符串
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
#include <string>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  template <typename _T> using vt = std::vector<_T>;
  template <size_t _N> using bits = std::bitset<_N>;

  int dp[30][30][30];
  bool dfs(string_view s1, string_view s2, int start1, int start2, int len) {
    int &x = dp[start1][start2][len];
    if (x != -1)
      return x;
    if (s1.substr(start1, len) == s2.substr(start2, len))
      return (x = true);
    vt<int> v(26), lv(26), rv(26);

    // std::cout << "-----------------" << start1 << " " << start2 << " " << len
    //           << std::endl;
    for (int k = 0; k < len; ++k) {
      v[s1[start1 + k] - 'a']++;
      lv[s2[start2 + k] - 'a']++;
      rv[s2[start2 + len - k - 1] - 'a']++;

      if (k == len - 1)
        break;
      if (v == lv and dfs(s1, s2, start1, start2, k + 1) and
          dfs(s1, s2, start1 + k + 1, start2 + k + 1, len - (k + 1)))
        return (x = true);
      if (v == rv and dfs(s1, s2, start1, start2 + len - k - 1, k + 1) and
          dfs(s1, s2, start1 + k + 1, start2, len - (k + 1)))
        return (x = true);
    }

    return (x = false);
  }

public:
  bool isScramble(string s1, string s2) {
    memset(dp, -1, sizeof(dp));
    return dfs(s1, s2, 0, 0, s1.size());
  }
};
// @lc code=end

/*
// @lcpr case=start
// "great"\n"rgeat"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n"caebd"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

 */
