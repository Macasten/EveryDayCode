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
    std::cout << "!! 472. Concatenated Words !!\n";
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
  std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string> &words)
  {
    std::unordered_set<std::string> words_set;
    for (auto word : words)
      words_set.insert(word);
    std::vector<std::string> res;

    for (auto word : words)
    {
      int n = word.size();
      std::vector<int> dp(n + 1, 0);
      dp[0] = 1;
      for (int i = 0; i < n; i++)
      {
        if (!dp[i])
          continue;
        for (int j = i + 1; j <= n; j++)
        {
          if (j - i < n && words_set.count(word.substr(i, j - i)))
          {
            dp[j] = 1;
          }
        }
        if (dp[n])
        {
          res.push_back(word);
          break;
        }
      }
    }
    return res;
  }
  // Challenge code - ENDED
  void runFindAllConcatenatedWordsInADict(std::vector<std::string> words, std::vector<std::string> expected)
  {
    resultValidation(findAllConcatenatedWordsInADict(words), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runFindAllConcatenatedWordsInADict(
      {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"},
      {"catsdogcats", "dogcatsdog", "ratcatdogcat"});
  solution.runFindAllConcatenatedWordsInADict(
      {"cat", "dog", "catdog"},
      {"catdog"});
  return 0;
}