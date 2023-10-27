/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30102
 *
 * [215] 数组中的第K个最大元素
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
  int getKth(std::vector<int> &nums, int l, int r, int k) {
    if (l == r)
      return nums[l];
    // j
    int index = l + rand() % (r - l);
    int pivot = nums[index];
    int i = l - 1, j = r + 1;
    while (i < j) {
      do
        i++;
      while (nums[i] > pivot);
      do
        j--;
      while (nums[j] < pivot);
      if (i < j)
        swap(nums[i], nums[j]);
    }
    // std::cout << pivot << " " << j << std::endl;
    // // clang-format off
    // for (auto& x : nums)
    //   std::cout << x << " ";
    // std::cout << std::endl;
    // // clang-format on
    if (k - 1 <= j)
      return getKth(nums, l, j, k);
    return getKth(nums, j + 1, r, k);
  }

public:
  int findKthLargest(vector<int> &nums, int k) {
    return getKth(nums, 0, nums.size() - 1, k);
  }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
