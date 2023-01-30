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
    std::cout << "!! 1137. N-th Tribonacci Number !!\n";
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
  int tribonacci(int n)
  {
    // first 3 elements
    if (n == 0)
      return 0;
    else if (n == 1)
      return 1;
    else if (n == 2)
      return 1;

    // next elements
    std::vector<int> elements(3, 0);
    elements.at(1) = 1;
    elements.at(2) = 1;
    while (n > 2)
    {
      int newN{elements.at(0)};
      newN += elements.at(1);
      elements.at(0) = elements.at(1);
      newN += elements.at(2);
      elements.at(1) = elements.at(2);
      elements.at(2) = newN;
      n--;
    }
    return elements.at(2);
  }
  // Challenge code - ENDED
  void runTribonacci(int n, int expected)
  {
    std::cout << tribonacci(n) << std::endl;
    resultValidation(tribonacci(n), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runTribonacci(1, 1);
  solution.runTribonacci(3, 2);
  solution.runTribonacci(4, 4);
  solution.runTribonacci(25, 1389537);
  return 0;
}