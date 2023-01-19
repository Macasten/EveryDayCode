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
    std::cout << "!! 974. Subarray Sums Divisible by K !!\n";
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
  int subarraysDivByK(std::vector<int> &nums, int k)
  {
    int n = nums.size();
    std::vector<int> sums(k, 0);
    sums[0]++;
    int cnt = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
      currSum = (currSum + nums[i] % k + k) % k;
      cnt += sums[currSum];
      sums[currSum]++;
    }
    return cnt;
  }
  // Challenge code - ENDED
  void runSubarraysDivByK(std::vector<int> nums, int k, int expected)
  {
    resultValidation(subarraysDivByK(nums, k), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runSubarraysDivByK({4, 5, 0, -2, -3, 1}, 5, 7);
  solution.runSubarraysDivByK({5}, 9, 0);
  solution.runSubarraysDivByK({5}, 5, 1);
  return 0;
}