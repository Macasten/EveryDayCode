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
    std::cout << "!! 409. Longest Palindrome !!\n";
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
  int longestPalindrome(std::string s)
  {
    std::map<char, int> m;
    for (auto l : s)
    {
      m[l]++;
    }
    int size = 0;
    int y = 0;
    for (auto j : m)
    {
      if (j.second % 2 == 0)
        size = size + j.second;
      else
      {
        size = size + (j.second - 1);
        y++;
      }
    }
    if (y > 0)
      size++;
    return size;
  }
  // Challenge code - ENDED
  void runLongestPalindrome(std::string s, int expected)
  {
    resultValidation(longestPalindrome(s), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runLongestPalindrome("Aa", 1);
  solution.runLongestPalindrome("abccccdd", 7);
  solution.runLongestPalindrome("a", 1);
  return 0;
}