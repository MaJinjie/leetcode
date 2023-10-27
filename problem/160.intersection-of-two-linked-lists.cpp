/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30102
 *
 * [160] 相交链表
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
  int listlen(ListNode *list) {
    int len = 0;
    while (list) {
      len++;
      list = list->next;
    }
    return len;
  }

public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = listlen(headA), lenB = listlen(headB);
    if (lenA > lenB) {
      swap(lenA, lenB);
      swap(headA, headB);
    }

    ListNode *pa = headA, *pb = headB;
    for (int i = 0; i < lenB - lenA; ++i)
      pb = pb->next;

    for (int i = 0; i < lenA; ++i, pa = pa->next, pb = pb->next) {
      if (pa == pb)
        return pa;
    }
    return nullptr;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
