/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30102
 *
 * [71] 简化路径
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  string simplifyPath(string path) {
    std::vector<std::string_view> st;
    int i = 0;
    int start, end;
    std::string_view sv(path);
    do {
      while (i < sv.size() and sv[i] == '/')
        i++;
      start = i;
      while (i < sv.size() and sv[i] != '/')
        i++;
      end = i;
      if (start != end) {
        auto s = sv.substr(start, end - start);
        if (s == ".")
          continue;
        else if (s == "..")
          !st.empty() ? st.pop_back() : void();
        else
          st.push_back(s);
      }
    } while (i < sv.size());

    std::string res;
    for (auto sv : st) {
      res += '/';
      res += sv;
    }
    return res.empty() ? "/" : res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/a/./b/../../c/"\n
// @lcpr case=end

 */
