/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=30102
 *
 * [496] 下一个更大元素 I
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    std::vector<int> res(n, -1);
    std::unordered_map<int, int> umap;
    for (int i = 0; i < n; ++i)
      umap[nums1[i]] = i;

    std::stack<int> st;
    for (auto num : nums2) {
      while (!st.empty() and st.top() < num) {
        int val = st.top();
        if (umap.contains(val))
          res[umap[val]] = num;
        st.pop();
      }
      st.push(num);
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */
