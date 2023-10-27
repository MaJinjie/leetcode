/*
 * @lc app=leetcode.cn id=659 lang=cpp
 * @lcpr version=30102
 *
 * [659] 分割数组为连续子序列
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
#include <queue>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  bool isPossible(vector<int> &nums) {
    // dp[i] : 以值i为最后一个元素的的所有子序列的长度
    // 因为nums[i]可能由多个，所以每一个nums[i]可能有多个连续的子序列
    // 所以，我们使用哈希表来存储状态。
    // 因为我们可以获取最小长度，所有使用优先队列而不是vector

    /*
    dp[i]
    if i - 1 exists: dp[i] = 1 + dp[i - 1]（最小 （其中，i-1对应的子序列个数减1)
    else dp[i] = 1 + 0;
*/
    using priority =
        std::priority_queue<int, std::vector<int>, std::greater<int>>;
    std::unordered_map<int, priority> umap;

    for (int num : nums) {
      int len = 0;
      if (umap.contains(num - 1) and !umap[num - 1].empty()) {
        len = umap[num - 1].top();
        umap[num - 1].pop();
      }
      umap[num].push(len + 1);
    }

    for (int num : nums) {
      if (!umap[num].empty() and umap[num].top() < 3)
        return false;
    }
    return true;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,3,4,4,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,4,5]\n
// @lcpr case=end

 */
