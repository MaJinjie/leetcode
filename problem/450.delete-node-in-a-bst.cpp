

/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30102
 *
 * [450] 删除二叉搜索树中的节点
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
  TreeNode *impl(TreeNode *root, int key) {
    if (!root)
      return nullptr;
    if (root->val > key)
      root->left = impl(root->left, key);
    else if (root->val < key)
      root->right = impl(root->right, key);
    else {
      TreeNode *to_delete = root;
      TreeNode *p = root->left;
      if (!p)
        root = root->right;
      else {
        while (p->right)
          p = p->right;
        p->right = root->right;
        root = root->left;
      }
      delete to_delete;
    }
    return root;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key) { return impl(root, key); }
};
// @lc code=end

/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
