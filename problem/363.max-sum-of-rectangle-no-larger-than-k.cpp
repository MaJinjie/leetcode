/*
 * @lc app=leetcode.cn id=363 lang=cpp
 * @lcpr version=30102
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

// @lcpr-template-start

#include "common.hpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int r = matrix.size(), c = matrix[0].size();
    std::vector<vector<int>> presums(r, std::vector<int>(1, 0));
    for (int i = 0; i < r; ++i) {
      auto &presum = presums[i];
      auto &nums = matrix[i];
      std::partial_sum(nums.begin(), nums.end(), std::back_inserter(presum));
    }

    int startj, endj;
    int res = INT_MIN;
    auto nums = [&presums, &startj, &endj](int i) {
      return presums[i][endj + 1] - presums[i][startj];
    };
    for (startj = 0; startj < c; ++startj) {
      for (endj = startj; endj < c; ++endj) {
        int presum = 0;
        std::set<int> oset;
        for (int i = 0; i < r; ++i) {
          oset.insert(presum);
          presum += nums(i);

          auto it = oset.lower_bound(presum - k);
          if (it != oset.end() and presum - *it > res)
            res = presum - *it;
        }
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,0,1],[0,-2,3]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,-1]]\n3\n
// @lcpr case=end

 */
