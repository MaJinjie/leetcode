/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30102
 *
 * [23] 合并 K 个升序链表
 */

// @lcpr-template-start

#include "common.hpp"
#include <bits/stdc++.h>
#include <queue>
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
  int listLen(ListNode *list) {
    int len = 0;
    while (list) {
      len++;
      list = list->next;
    }
    return len;
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() <= 1)
      return lists.empty() ? nullptr : lists[0];
    using e_t = std::pair<int, ListNode *>;
    std::priority_queue<e_t, std::vector<e_t>, std::greater<e_t>> heap;

    for (auto list : lists)
      heap.push(std::make_pair(listLen(list), list));

    auto dummy = new ListNode();
    while (heap.size() >= 2) {
      auto [len1, list1] = heap.top();
      heap.pop();
      auto [len2, list2] = heap.top();
      heap.pop();

      // 合并操作
      auto tail = dummy;
      tail->next = nullptr;
      while (list1 and list2) {
        if (list1->val > list2->val)
          tail->next = list2, list2 = list2->next;
        else
          tail->next = list1, list1 = list1->next;
        tail = tail->next;
      }
      if (list1)
        tail->next = list1;
      else
        tail->next = list2;
      while (tail->next)
        tail = tail->next;

      heap.push(std::make_pair(len1 + len2, dummy->next));
    }
    return dummy->next;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */
