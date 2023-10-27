/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30102
 *
 * [437] 路径总和 III
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
  long presum;
  std::map<long, int> omap;

public:
  // 把它转换为区间和问题，由于区间和是一个定值，可以使用哈希表进行计算
  int pathSum(TreeNode *root, int targetSum) {
    if (!root)
      return 0;
    int res = 0;
    omap[presum]++;
    presum += root->val;

    res += omap[presum - targetSum];
    res += pathSum(root->left, targetSum);
    res += pathSum(root->right, targetSum);

    presum -= root->val;
    --omap[presum];
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
