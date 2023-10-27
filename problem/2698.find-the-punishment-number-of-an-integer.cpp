/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 * @lcpr version=30102
 *
 * [2698] 求一个整数的惩罚数
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  bool is_success(int n, int cursum, int target) {
    if (n == 0)
      return cursum == target;

    int val = 0;
    int multi = 1;
    while (n != 0) {
      val += multi * (n % 10);
      if (cursum + val > target)
        break;
      n /= 10;
      if (is_success(n, cursum + val, target))
        return true;
      multi *= 10;
    }
    return false;
  }

public:
  int punishmentNumber(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (is_success(i * i, 0, i))
        res += i * i;
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 37\n
// @lcpr case=end

 */
