/*
 * @lc app=leetcode.cn id=306 lang=cpp
 * @lcpr version=30102
 *
 * [306] 累加数
 */

// @lcpr-template-start

#include "common.hpp"
#include <array>
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  std::string add_impl(std::string_view num, int i, int j, int k) {
    int carry = 0;
    std::string res;
    int loopi = j - 1, loopj = k - 1;
    for (; loopi >= i or loopj >= j or carry; loopi--, loopj--) {
      if (loopi >= i)
        carry += num[loopi] - '0';
      if (loopj >= j)
        carry += num[loopj] - '0';
      res += ('0' + carry % 10);
      carry /= 10;
    }
    std::reverse(res.begin(), res.end());
    // std::cout << i << " " << j << " " << k << " " << res << std::endl;

    return res;
  }
  bool is_success(std::string_view num, int i, int j, int k) {
    if (k == num.size())
      return true;
    if (j != i + 1 and num[i] == '0')
      return false;
    if (k != j + 1 and num[j] == '0')
      return false;
    std::string res = add_impl(num, i, j, k);
    if (res.compare(num.substr(k, res.size())) != 0)
      return false;
    return is_success(num, j, k, k + res.size());
  }

public:
  bool isAdditiveNumber(string num) {
    // mei ju
    int i = 0;
    int j, k;
    for (j = i + 1; j < num.size() - 1; ++j) {
      for (k = j + 1; k < num.size(); ++k) {
        if (is_success(num, i, j, k))
          return true;
      }
    }
    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "112358"\n
// @lcpr case=end

// @lcpr case=start
// "199100199"\n
// @lcpr case=end

 */
