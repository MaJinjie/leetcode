/*
 * @lc app=leetcode.cn id=939 lang=cpp
 * @lcpr version=30102
 *
 * [939] 最小面积矩形
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
#include <functional>
using namespace std;
// @lcpr-template-end
// @lc code=start

class Solution {
  std::set<pair<int, int>> uset;
  std::pair<int, int> to_pair(std::vector<int> &nums) {
    return std::make_pair(nums[0], nums[1]);
  }
  bool valid(const std::pair<int, int> &p1, const pair<int, int> &p2) {
    auto p3 = std::make_pair(p1.first, p2.second);
    auto p4 = std::make_pair(p2.first, p1.second);
    return get<0>(p1) != get<0>(p2) and get<1>(p1) != get<1>(p2) and
           uset.contains(p3) and uset.contains(p4);
  }
  int cal(const std::pair<int, int> &p1, const pair<int, int> &p2) {
    return abs(p1.first - p2.first) * abs(p1.second - p2.second);
  }

public:
  int minAreaRect(vector<vector<int>> &points) {
    // 矩形由四个点组成，当三个点确定时
    std::unordered_set<pair<int, int>> uset;

    for (auto &point : points) {
      uset.insert(to_pair(point));
    }
    int n = points.size();
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        auto point1 = to_pair(points[i]);
        auto point2 = to_pair(points[j]);
        if (valid(point1, point2))
          res = min(res, cal(point1, point2));
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};
template <> struct std::hash<pair<int, int>> {
  size_t operator()(const pair<int, int> &p) {
    return 10 * p.first + 100 * p.second;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1],[1,3],[3,1],[3,3],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]\n
// @lcpr case=end

 */
