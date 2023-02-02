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
    std::cout << "!! 953. Verifying an Alien Dictionary !!\n";
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
  bool isAlienSorted(std::vector<std::string> &words, std::string order)
  {
    if (words.size() <= 1)
      return true;

    std::string top{words.at(0)};
    std::string bottom{""};
    for (uint i = 1; i < words.size(); i++)
    {
      bottom = words.at(i);
      for (uint j = 0; j < top.size(); j++)
      {
        int orderIndex = static_cast<int>(order.find(top.at(j))) - static_cast<int>(order.find(bottom.at(j)));
        if (orderIndex < 0)
          break;
        else if (orderIndex > 0)
          return false;
        else if (orderIndex == 0 && j == bottom.size() - 1 && j != top.size() - 1)
          return false;
      }
      top = bottom;
    }

    return true;
  }
  // Challenge code - ENDED
  void runIsAlienSorted(std::vector<std::string> words, std::string order, bool expected)
  {
    resultValidation(isAlienSorted(words, order), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runIsAlienSorted({"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz", true);
  solution.runIsAlienSorted({"word", "world", "row"}, "worldabcefghijkmnpqstuvxyz", false);
  solution.runIsAlienSorted({"apple", "app"}, "abcdefghijklmnopqrstuvwxyz", false);
  solution.runIsAlienSorted({"hello", "hello"}, "abcdefghijklmnopqrstuvwxyz", true);

  return 0;
}