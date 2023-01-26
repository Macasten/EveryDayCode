////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

////////////////////////////////////////////////////////////////////////////////
// Personal Helpers
////////////////////////////////////////////////////////////////////////////////

#include "Print.h"
#include "TreeNode.h"
#include "ListNode.h"

////////////////////////////////////////////////////////////////////////////////
// Solution
////////////////////////////////////////////////////////////////////////////////
class Solution
{
private:
  int test{0};

public:
  Solution() {}

  void showChallengeTitle()
  {
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "!! 876. Middle of the Linked List !!\n";
    std::cout << "-------------------------------------------------------------\n";
  }

  void startTest()
  {
    std::cout << "---------------" << std::endl;
    std::cout << "Test #" << test << std::endl;
    std::cout << "---------------" << std::endl;
    test++;
  }

  void endTest()
  {
    std::cout << "-- TEST ENDED --" << std::endl;
  }

  template <typename T>
  void resultValidation(const T &t, const T &r)
  {
    if (t == r)
      std::cout << "SUCCEED" << std::endl;
    else
      std::cout << "FAILED" << std::endl;
  }
  // Challenge code - START
  inline size_t nodeCount(ListNode *head)
  {
    size_t count{0};
    while (head != nullptr)
    {
      count++;
      head = head->next;
    }
    return count;
  }

  inline ListNode *getNode(ListNode *head, size_t index)
  {
    while (index > 0)
    {
      if (head == nullptr)
      {
        break;
      }
      head = head->next;
      index--;
    }
    return head;
  }

  ListNode *middleNode(ListNode *head)
  {

    ListNode *next = head;

    if (next == nullptr || next->next == nullptr)
    {
      return next;
    }

    size_t count{nodeCount(head)};

    return getNode(head, (count / 2));
  }
  // Challenge code - ENDED
  void runMiddleNode(std::vector<int> list, int expected)
  {
    auto head = ListNode::build(list);
    resultValidation(middleNode(head)->val, expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runMiddleNode({1, 2, 3, 4, 5}, 3);
  solution.runMiddleNode({1, 2, 3, 4, 5, 6}, 4);
  return 0;
}