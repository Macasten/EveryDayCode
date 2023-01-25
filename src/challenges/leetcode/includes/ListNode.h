#ifndef LISTNODE_H
#define LISTNODE_H

////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

////////////////////////////////////////////////////////////////////////////////
// ListNode
////////////////////////////////////////////////////////////////////////////////
// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}

  static ListNode *build(const std::vector<int> &list)
  {
    if (list.empty())
      return new ListNode;
    ListNode *output = new ListNode(list.front());
    ListNode *next = output;
    for (size_t i = 1; i < list.size(); i++)
    {
      next->next = new ListNode(list.at(i));
      next = next->next;
    }
    return output;
  }

  std::vector<int> getData() const
  {
    std::vector<int> output{val};
    ListNode *nextNode = next;
    while (nextNode)
    {
      output.push_back(nextNode->val);
      nextNode = nextNode->next;
    }
    return output;
  }
};

inline bool operator==(const ListNode &lhs, const ListNode &rhs)
{
  return lhs.getData() == rhs.getData();
}

#endif
