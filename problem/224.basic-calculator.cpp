/*
 * @lc app=leetcode.cn id=224 lang=cpp
 * @lcpr version=30102
 *
 * [224] 基本计算器
 */

// @lcpr-template-start

#include "common.hpp"
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <charconv>
#include <stdexcept>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  template <typename _T> using vt = std::vector<_T>;
  template <size_t _N> using bits = std::bitset<_N>;
  int index;
  int getDigit(std::string_view sv) {
    int val;
    auto result = std::from_chars(sv.begin() + index, sv.end(), val);
    this->index = result.ptr - sv.begin();
    // std::cout << this->index << std::endl;
    return val;
  }

  // 把括号看作一个优先级更高的计算单元，普通的数值是一个低级的计算单元
  int cal(std::string_view sv) {
    int res = 0;
    int sign = 1;
    do {
      if (sv[this->index] == '(')
        this->index++, res += sign * cal(sv), this->index++;
      else if (sv[this->index] == ' ')
        this->index++;
      else if (sv[this->index] == '+')
        this->index++, sign = 1;
      else if (sv[this->index] == '-')
        this->index++, sign = -1;
      else
        res += sign * getDigit(sv);
    } while (this->index < sv.size() and sv[this->index] != ')');
    return res;
  }

public:
  int calculate(string s) { return cal(s); }
};
// @lc code=end

/*
// @lcpr case=start
// "1 + 1"\n
// @lcpr case=end

// @lcpr case=start
// " 2-1 + 2 "\n
// @lcpr case=end

// @lcpr case=start
// "(1+(4+5+2)-3)+(6+8)"\n
// @lcpr case=end

 */
