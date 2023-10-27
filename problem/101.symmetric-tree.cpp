/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30102
 *
 * [101] 对称二叉树
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
  bool dfs(TreeNode *left, TreeNode *right) {
    if (!left)
      return !right;
    if (!right)
      return !left;
    return left->val == right->val and dfs(left->left, right->right) and
           dfs(left->right, right->left);
  }

public:
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    return dfs(root->left, root->right);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
