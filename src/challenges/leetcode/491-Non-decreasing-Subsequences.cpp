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
    std::cout << "!! 491. Non-decreasing Subsequences !!\n";
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
  // Recursive function to find all increasing subsequences
  void solve(std::vector<int> nums, int index, std::vector<int> output, std::set<std::vector<int>> &ans)
  {
    // Base case: if we have reached the end of the input array
    if (index >= nums.size())
    {
      // Only insert into ans if output has more than one element
      if (output.size() > 1)
        ans.insert(output);
      return;
    }
    // If output is empty or current element is greater than or equal to the last element in output
    if (output.size() == 0 || nums[index] >= output.back())
    {
      output.push_back(nums[index]);
      solve(nums, index + 1, output, ans);
      output.pop_back();
    }
    solve(nums, index + 1, output, ans);
  }

  std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums)
  {
    // Initialize output and set to store all increasing subsequences
    std::vector<int> output;
    std::set<std::vector<int>> ans;
    // Call recursive function to find all increasing subsequences
    solve(nums, 0, output, ans);
    // Return ans as a vector
    return std::vector<std::vector<int>>(ans.begin(), ans.end());
  }
  // Challenge code - ENDED
  void runFindSubsequences(std::vector<int> nums, std::vector<std::vector<int>> expected)
  {
    resultValidation(findSubsequences(nums), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runFindSubsequences(
      {4, 6, 7, 7},
      {{4, 6}, {4, 6, 7}, {4, 6, 7, 7}, {4, 7}, {4, 7, 7}, {6, 7}, {6, 7, 7}, {7, 7}});
  return 0;
}