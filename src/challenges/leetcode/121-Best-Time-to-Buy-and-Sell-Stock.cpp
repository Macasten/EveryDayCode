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
    std::cout << "!! 121. Best Time to Buy and Sell Stock !!\n";
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
  int maxProfit(std::vector<int> &prices)
  {
    if (prices.size() < 2)
      return 0;

    int output{0};
    for (int i = 0; i < prices.size() - 1;)
    {
      int by{prices.at(i)};
      int sel{*std::max_element(prices.begin() + i + 1, prices.end())};
      output = std::max(output, (sel - by));

      while (i < prices.size() - 1)
      {
        if (by > prices.at(i + 1))
        {
          i++;
          break;
        }
        i++;
      }
    }
    return output;
  }
  // Challenge code - ENDED
  void runMaxProfit(std::vector<int> prices, int expected)
  {
    std::cout << maxProfit(prices) << std::endl;
    resultValidation(maxProfit(prices), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runMaxProfit({1, 2}, 1);
  solution.runMaxProfit({7, 1, 5, 3, 6, 4}, 5);
  solution.runMaxProfit({7, 6, 4, 3, 1}, 0);
  return 0;
}