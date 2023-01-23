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
    std::cout << "!! 724. Find Pivot Index !!\n";
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
  int pivotIndex(std::vector<int> &nums)
  {
    if (nums.size() == 1)
      return 0;
    if (nums.size() % 2 == 2)
      return -1;

    std::vector<int> smun(nums.rbegin(), nums.rend());
    for (int i = 1; i < nums.size(); i++)
    {
      nums.at(i) += nums.at(i - 1);
      smun.at(i) += smun.at(i - 1);
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums.at(i) == smun.at(smun.size() - i - 1))
        return i;
    }
    return -1;
  }
  // Challenge code - ENDED
  void runPivotIndex(std::vector<int> nums, int expected)
  {
    resultValidation(pivotIndex(nums), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runPivotIndex({1, 7, 3, 6, 5, 6}, 3);
  solution.runPivotIndex({1, 2, 3}, -1);
  solution.runPivotIndex({2, 1, -1}, 0);
  return 0;
}