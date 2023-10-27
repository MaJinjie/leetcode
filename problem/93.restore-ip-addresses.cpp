/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30102
 *
 * [93] 复原 IP 地址
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  std::vector<string> res;
  std::vector<string_view> path;
  void add() {
    std::string s;
    for (auto sv : path) {
      s += sv;
      s += '.';
    }
    s.pop_back();
    res.push_back(std::move(s));
  }
  void dfs(std::string_view sv, int start) {
    if (path.size() == 4 and start == sv.size()) {
      add();
      return;
    }
    for (int len = 1; len <= 3; ++len) {
      if (start + len > sv.size())
        break;
      if (len < 3 or sv.substr(start, len) <= "255") {
        path.push_back(sv.substr(start, len));
        dfs(sv, start + len);
        path.pop_back();
      }
      if (sv[start] == '0')
        break;
    }
  }

public:
  vector<string> restoreIpAddresses(string s) {
    int n = s.size();
    if (n < 4 or n > 12)
      return {};
    dfs(s, 0);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */
