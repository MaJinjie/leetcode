/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30102
 *
 * [114] 二叉树展开为链表
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
  TreeNode *pre = nullptr;

public:
  // 使用后序遍历
  void flatten(TreeNode *root) {
    if (root) {
      flatten(root->right);
      flatten(root->left);
      root->right = pre;
      root->left = nullptr;
      pre = root;
    }
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
