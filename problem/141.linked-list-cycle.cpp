/*
 * @lc app=leetcode.cn id=141 lang=cpp
 * @lcpr version=30102
 *
 * [141] 环形链表
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (slow) {
      slow = slow->next;
      if (!fast or !fast->next)
        break;
      fast = fast->next->next;
      if (slow == fast)
        return true;
    }
    return false;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */
