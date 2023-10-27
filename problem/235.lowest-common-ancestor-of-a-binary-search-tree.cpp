/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30102
 *
 * [235] 二叉搜索树的最近公共祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root or root == p or root == q)
      return root;
    if (std::max(p->val, q->val) < root->val)
      return lowestCommonAncestor(root->left, p, q);
    if (std::min(p->val, q->val) > root->val)
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */
