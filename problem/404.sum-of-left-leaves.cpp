/*
 * @lc app=leetcode.cn id=404 lang=cpp
 * @lcpr version=30102
 *
 * [404] 左叶子之和
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
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
  constexpr bool is_leaf(TreeNode *root) {
    return root and !root->left and !root->right;
  }

public:
  // 只对左子树判断是否是左叶子节点
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;
    int res = 0;
    if (is_leaf(root->left))
      res += root->left->val;
    else
      res += sumOfLeftLeaves(root->left);
    res += sumOfLeftLeaves(root->right);
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
