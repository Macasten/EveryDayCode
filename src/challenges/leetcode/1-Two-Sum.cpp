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
    std::cout << "!! 1. Two Sum !!\n";
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
  std::vector<int> twoSum(std::vector<int> &nums, int target)
  {
    for (size_t i = 0; i < nums.size() - 1; i++)
    {
      for (size_t j = i + 1; j < nums.size(); j++)
      {
        if (nums.at(i) + nums.at(j) == target)
          return {static_cast<int>(i), static_cast<int>(j)};
      }
    }
    return {-1, -1};
  }
  // Challenge code - ENDED
  void runTwoSum(std::vector<int> nums, int target, std::vector<int> expected)
  {
    resultValidation(twoSum(nums, target), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runTwoSum({2, 7, 11, 15}, 9, {0, 1});
  solution.runTwoSum({3, 2, 4}, 6, {1, 2});
  solution.runTwoSum({3, 3}, 6, {0, 1});
  return 0;
}