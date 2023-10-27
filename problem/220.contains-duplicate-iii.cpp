/*
 * @lc app=leetcode.cn id=220 lang=cpp
 * @lcpr version=30102
 *
 * [220] 存在重复元素 III
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff,
                                     int valueDiff) {
    const int bucket_range = valueDiff + 1;
    const int n = nums.size();
    auto get_id = [&](int value) {
      if (value >= 0)
        return value / bucket_range;
      return (value + 1) / bucket_range - 1;
    };
    std::unordered_map<int, int> umap;

    for (int left = 0, right = 0; right < n; ++right) {
      const int bucket_id = get_id(nums[right]);
      if (umap.contains(bucket_id))
        return true;
      if (umap.contains(bucket_id - 1) and
          nums[right] - umap[bucket_id - 1] <= valueDiff)
        return true;
      if (umap.contains(bucket_id + 1) and
          umap[bucket_id + 1] - nums[right] <= valueDiff)
        return true;

      umap[bucket_id] = nums[right];
      if (right - left >= indexDiff) {
        const int bucket_id = get_id(nums[left]);
        umap.erase(bucket_id);
        left++;
      }
    }
    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n3\n0\n
// @lcpr case=end

// @lcpr case=start
// [1,5,9,1,5,9]\n2\n3\n
// @lcpr case=end

 */
