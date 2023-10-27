/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30102
 *
 * [654] 最大二叉树
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
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    // 递减栈 为了寻找下一个更大的元素。
    // 如果找到下一个更大的元素，将栈中小于它的元素构造成一棵子树挂在它的左边
    // 遍历一次，还在栈中的元素会构成一颗右先树，把他连接起来
    std::stack<TreeNode *> st;
    TreeNode *tree;
    for (int num : nums) {
      tree = nullptr;
      while (!st.empty() and st.top()->val < num) {
        auto tmp = st.top();
        st.pop();
        tmp->right = tree;
        tree = tmp;
      }
      st.push(new TreeNode(num, tree, nullptr));
    }
    tree = nullptr;
    while (!st.empty()) {
      auto tmp = st.top();
      st.pop();
      tmp->right = tree;
      tree = tmp;
    }
    return tree;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */
