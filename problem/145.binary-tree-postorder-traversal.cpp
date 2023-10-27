/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30102
 *
 * [145] 二叉树的后序遍历
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
#include <type_traits>
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
public:
  vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> res;
    std::stack<TreeNode *> st;
    auto cur = root;
    while (cur or !st.empty()) {
      while (cur) {
        st.push(cur);
        if (cur->right)
          st.push(nullptr);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      if (cur == nullptr)
        cur = st.top()->right;
      else
        res.push_back(cur->val), cur = {};
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
