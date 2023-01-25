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
    std::cout << "!! 206. Reverse Linked List !!\n";
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
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    while (head->next)
    {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    head->next = prev;

    return head;
  }
  // Challenge code - ENDED
  void runReverseList(std::vector<int> list, std::vector<int> expected)
  {
    auto temp = ListNode::build(list);
    auto expe = ListNode::build(expected);
    temp = reverseList(temp);
    resultValidation(*temp, *expe);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runReverseList({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
  solution.runReverseList({1, 2}, {2, 1});
  return 0;
}