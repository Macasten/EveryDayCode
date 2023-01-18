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
    std::cout << "!! 918. Maximum Sum Circular Subarray !!\n";
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
  int maxSubarraySumCircular(std::vector<int> &A)
  {
    int total_sum = 0, curr_sum1 = 0, curr_sum2 = 0, mxsum_subary = INT_MIN, minsum_subary = INT_MAX;
    for (auto i : A)
    {
      total_sum += i;
      curr_sum1 += i;
      curr_sum2 += i;
      mxsum_subary = std::max(mxsum_subary, curr_sum1);
      if (curr_sum1 < 0)
        curr_sum1 = 0;
      minsum_subary = std::min(curr_sum2, minsum_subary);
      if (curr_sum2 > 0)
        curr_sum2 = 0;
    }
    return (total_sum == minsum_subary) ? mxsum_subary : std::max(mxsum_subary, total_sum - minsum_subary);
  }
  // Challenge code - ENDED
  void runMaxSubarraySumCircular(std::vector<int> A, int expected)
  {
    auto result = maxSubarraySumCircular(A);
    resultValidation(result, expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runMaxSubarraySumCircular({1, -2, 3, -2}, 3);
  solution.runMaxSubarraySumCircular({1, -2, 3, 4, 0, -2}, 7);
  return 0;
}