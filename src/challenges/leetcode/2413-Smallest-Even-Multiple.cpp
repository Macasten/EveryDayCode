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
    std::cout << "!! 2413. Smallest Even Multiple !!\n";
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
  int smallestEvenMultiple(int n)
  {
    return (n % 2 == 0) ? n : n * 2;
  }
  // Challenge code - ENDED
  void runSmallestEventMultiple(int n, int expected)
  {
    resultValidation(smallestEvenMultiple(n), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runSmallestEventMultiple(1, 2);
  solution.runSmallestEventMultiple(2, 2);
  solution.runSmallestEventMultiple(3, 6);
  return 0;
}