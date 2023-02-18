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
    std::cout << "!! 746. Min Cost Climbing Stairs !!\n";
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
  int minCostClimbingStairs(std::vector<int> &cost)
  {
    int n = cost.size();
    for (int i = 2; i < n; i++)
    {
      cost[i] += std::min(cost[i - 1], cost[i - 2]);
    }
    return std::min(cost[n - 1], cost[n - 2]);
  }
  // Challenge code - ENDED
  void runMinCostClimbingStairs(std::vector<int> cost, int expected)
  {
    resultValidation(minCostClimbingStairs(cost), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();

  solution.runMinCostClimbingStairs({10, 15, 20}, 15);
  solution.runMinCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6);

  return 0;
}