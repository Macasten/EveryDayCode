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
    std::cout << "!! 392. Is Subsequence !!\n";
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

  /**
   * @brief
   *
   * Constraints:
   * 0 <= s.length <= 100
   * 0 <= t.length <= 104
   * s and t consist only of lowercase English letters.
   *
   * @param s
   * @param t
   * @return true
   * @return false
   */
  bool isSubsequence_v1(std::string s, std::string t)
  {
    if (s.empty())
      return true;
    if (t.empty())
      return false;

    int indexS{0};
    int indexT{0};
    while (indexS < s.size() && indexT < t.size())
    {
      if (s.at(indexS) == t.at(indexT))
      {
        indexS++;
      }
      indexT++;
    }
    return (indexS == s.size());
  }

  bool isSubsequence_v2(std::string s, std::string t)
  {
    if (s.length() == 0)
      return true;

    if (s.length() > t.length())
      return false;

    for (size_t i = 0; i < t.length(); i++)
    {
      if (s.front() != t.at(i) && s.length() > t.length() - i)
        return false;
      if (s.front() == t.at(i))
        s.erase(s.begin());
      if (s.length() == 0)
        return true;
    }

    return false;
  }

  bool isSubsequence_v3(std::string s, std::string t)
  {
    if (s.length() == 0)
      return true;

    if (s.length() > t.length())
      return false;

    int indexS{0};
    int indexT{0};
    while (indexS < s.size() && indexT < t.size())
    {
      if (s.at(indexS) == t.at(indexT))
      {
        indexS++;
      }
      indexT++;
    }
    return (indexS == s.size());
  }

  bool isSubsequence_v4(std::string s, std::string t)
  {
    if (s.length() == 0)
      return true;

    if (s.length() > t.length())
      return false;

    int indexS{0};
    int indexT{0};
    while (indexS < s.size() && indexT < t.size())
    {
      if (s.at(indexS) == t.at(indexT))
      {
        indexS++;
        if (indexS == s.length())
          return true;
      }
      indexT++;
      if (s.length() - indexS > t.length() - indexT)
        return false;
    }
    return (indexS == s.size());
  }
  // Challenge code - ENDED
  void runIsSubsequence(std::string s, std::string t, bool expected)
  {
    resultValidation(isSubsequence(s, t), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runIsSubsequence("abc", "ahbgdc", true);
  solution.runIsSubsequence("axc", "ahbgdc", false);

  return 0;
}