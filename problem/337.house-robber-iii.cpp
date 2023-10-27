/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=30102
 *
 * [337] 打家劫舍 III
 */

// @lcpr-template-start

#include <map>
#include <set>
using namespace std;
#include "common.hpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  std::unordered_map<TreeNode *, int> dp; // 不偷窃当前房屋所获得的最大利润
  int _rob(TreeNode *root) {
    if (!root)
      return 0;
    auto left = _rob(root->left);
    auto right = _rob(root->right);

    dp[root] = left + right;

    return max(left + right, root->val + dp[root->left] + dp[root->right]);
  }

public:
  int rob(TreeNode *root) {
    dp[nullptr] = 0;
    return _rob(root);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */
