/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30102
 *
 * [19] 删除链表的倒数第 N 个结点
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // 要找打倒数第n + 1个节点
    auto dummy = new ListNode(0, head);
    ListNode *del = dummy, *p = dummy;
    for (int step = 0; p->next; p = p->next, step++) {
      // p 走到倒数第1个节点，而 del要走到倒数第n + 1个节点
      // 因此，del要迟走n步,当p走完n步时，它就可以走了
      if (step >= n)
        del = del->next;
    }
    auto tmp = del->next;
    del->next = tmp->next;
    delete tmp;
    return dummy->next;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
