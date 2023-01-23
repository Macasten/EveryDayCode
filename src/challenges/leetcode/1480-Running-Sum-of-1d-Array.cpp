////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

////////////////////////////////////////////////////////////////////////////////
// Personal Helpers
////////////////////////////////////////////////////////////////////////////////

#include "Print.h"
#include "TreeNode.h"

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
    std::cout << "!! 1480. Running Sum of 1d Array !!\n";
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
  std::vector<int> runningSum(std::vector<int> &nums)
  {
    for (int i = 1; i < nums.size(); i++)
    {
      nums.at(i) += nums.at(i - 1);
    }
    return nums;
  }
  // Challenge code - ENDED
  void runRunningSum(std::vector<int> nums, std::vector<int> expected)
  {
    resultValidation(runningSum(nums), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runRunningSum({1, 2, 3, 4}, {1, 3, 6, 10});
  solution.runRunningSum({1, 1, 1, 1, 1}, {1, 2, 3, 4, 5});
  solution.runRunningSum({3, 1, 2, 10, 1}, {3, 4, 6, 16, 17});
  return 0;
}