/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30102
 *
 * [86] 分隔链表
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    auto dummy = new ListNode(0, head);
    ListNode *res = new ListNode(0, nullptr);
    auto tail = res;

    for (auto p = dummy; p->next;) {

      if (p->next->val < x) {
        tail->next = p->next;
        tail = tail->next;
        p->next = tail->next;
      } else {
        p = p->next;
      }
    }
    tail->next = dummy->next;

    return res->next;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
