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
    std::cout << "!! 977. Squares of a Sorted Array !!\n";
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
  std::vector<int> sortedSquares(std::vector<int> &nums)
  {
    std::for_each(nums.begin(), nums.end(), [](int &x)
                  { x *= x; });
    std::sort(nums.begin(), nums.end());
    return nums;
  }
  // Challenge code - ENDED
  void runSortedSquares(std::vector<int> nums, std::vector<int> expected)
  {
    resultValidation(sortedSquares(nums), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();

  solution.runSortedSquares({-4, -1, 0, 3, 10}, {0, 1, 9, 16, 100});
  solution.runSortedSquares({-7, -3, 2, 3, 11}, {4, 9, 9, 49, 121});
  return 0;
}