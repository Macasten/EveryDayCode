////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
#include <numeric>

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
    std::cout << "!! 1071. Greatest Common Divisor of Strings !!\n";
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
  std::string gcdOfStrings(std::string str1, std::string str2)
  {
    // ! std::gcd only available on c++ 17
    return (str1 + str2 == str2 + str1) ? str1.substr(0, std::gcd(size(str1), size(str2))) : "";
  }
  // Challenge code - ENDED
  void runGcdOfStrings(std::string str1, std::string str2, std::string expected)
  {
    resultValidation(gcdOfStrings(str1, str2), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runGcdOfStrings("ABCABC", "ABC", "ABC");
  solution.runGcdOfStrings("ABABAB", "ABAB", "AB");
  solution.runGcdOfStrings("LEET", "CODE", "");
  return 0;
}