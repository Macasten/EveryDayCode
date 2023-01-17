////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

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
    std::cout << "!! 926. Flip String to Monotone Increasing !!\n";
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
  int minFlipsMonoIncr(std::string s)
  {
    int count_flip = 0, count_one = 0;
    for (auto i : s)
    {
      // keep track of all one (we will use count_one in else condition if we need)
      // if we want flip one into 0
      if (i == '1')
        count_one++;
      else
      {
        count_flip++;
        count_flip = std::min(count_flip, count_one);
      }
    }
    return count_flip;
  }

  // Challenge code - ENDED
  void runMinFlipsMonoIncr(std::string s, int expected)
  {
    auto result = minFlipsMonoIncr(s);
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
  solution.runMinFlipsMonoIncr("00110", 1);
  solution.runMinFlipsMonoIncr("010110", 2);
  solution.runMinFlipsMonoIncr("00011000", 2);
  solution.runMinFlipsMonoIncr("00101000", 2);
  solution.runMinFlipsMonoIncr("1111001110", 3);
  solution.runMinFlipsMonoIncr("0101100011", 3);

  return 0;
}