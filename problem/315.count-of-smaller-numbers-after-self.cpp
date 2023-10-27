/*
 * @lc app=leetcode.cn id=315 lang=cpp
 * @lcpr version=30102
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  std::vector<int> res;
  std::vector<pair<int, int>> sorted;

public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    std::vector<pair<int, int>> sorting(n);
    for (int i = 0; i < n; ++i)
      sorting[i] = std::make_pair(nums[i], i);
    res.resize(n);
    divide(sorting, 0, n - 1);
    return res;
  }
  void merge(std::vector<pair<int, int>> &sorting, int l, int mid, int r) {
    for (int i = l, j = mid + 1; i <= mid; ++i) {
      while (j <= r and std::get<0>(sorting[j]) < get<0>(sorting[i]))
        j++;
      res[get<1>(sorting[i])] += j - (mid + 1);
    }
    sorted.clear();
    auto inserter = std::back_inserter(sorted);

    int i = l, j = mid + 1;
    while (i <= mid or j <= r) {
      if (i > mid or (j <= r and get<0>(sorting[j]) < get<0>(sorting[i])))
        *inserter++ = sorting[j++];
      else
        *inserter++ = sorting[i++];
    }
    std::move(sorted.begin(), sorted.end(), sorting.begin() + l);
  }
  void divide(std::vector<pair<int, int>> &sorting, int l, int r) {
    if (l >= r)
      return;
    int mid = l + (r - l) / 2;
    divide(sorting, l, mid);
    divide(sorting, mid + 1, r);
    merge(sorting, l, mid, r);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [5,2,6,1]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1]\n
// @lcpr case=end

 */
