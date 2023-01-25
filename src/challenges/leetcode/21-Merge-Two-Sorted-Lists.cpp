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
    std::cout << "!! 21. Merge Two Sorted Lists !!\n";
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
  void mergeToList(ListNode *baseList, ListNode *newList)
  {
    ListNode *nextNode = baseList;
    while (newList != nullptr)
    {
      if (nextNode->next == nullptr)
      {
        nextNode->next = newList;
        return;
      }

      if (nextNode->next->val >= newList->val)
      {
        ListNode *bAux = nextNode->next;
        ListNode *nAux = newList->next;
        nextNode->next = newList;
        nextNode->next->next = bAux;
        newList = nAux;
      }
      else
      {
        nextNode = nextNode->next;
      }
    }
  }
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    if (list1->val < list2->val)
    {
      mergeToList(list1, list2);
      return list1;
    }
    else
    {
      mergeToList(list2, list1);
      return list2;
    }
  }
  // Challenge code - ENDED
  void runMergeTwoLists(std::vector<int> list1, std::vector<int> list2, std::vector<int> expected)
  {
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  return 0;
}