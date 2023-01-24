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
    std::cout << "!! 205. Isomorphic Strings !!\n";
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
  bool isIsomorphic(std::string s, std::string t)
  {
    // String with length equal to one
    if (s.size() == 1)
      return true;

    std::unordered_map<char, char> mp, mp2;
    for (int i = 0; i < s.length(); ++i)
    {
      if (mp[s[i]] && mp[s[i]] != t[i])
        return false;
      if (mp2[t[i]] && mp2[t[i]] != s[i])
        return false;
      mp[s[i]] = t[i];
      mp2[t[i]] = s[i];
    }
    return true;
  }
  // Challenge code - ENDED
  void runIsIsomorphic(std::string s, std::string t, bool expected)
  {
    resultValidation(isIsomorphic(s, t), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runIsIsomorphic("egg", "add", true);
  solution.runIsIsomorphic("paper", "title", true);
  return 0;
}