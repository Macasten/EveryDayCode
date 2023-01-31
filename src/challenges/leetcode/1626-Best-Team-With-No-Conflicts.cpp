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
    std::cout << "!! 1626. Best Team With No Conflicts !!\n";
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
  int bestTeamScore(std::vector<int> &scores, std::vector<int> &ages)
  {
    int n = scores.size();
    int dp[n], ans = 0;
    std::vector<std::pair<int, int>> players;
    for (int i = 0; i < n; i++)
      players.push_back({ages[i], scores[i]});
    std::sort(players.begin(), players.end());
    for (int i = 0; i < n; i++)
    {
      dp[i] = players[i].second;
      for (int j = 0; j < i; j++)
      {
        if (players[j].second <= players[i].second)
          dp[i] = std::max(dp[i], dp[j] + players[i].second);
      }
      ans = std::max(ans, dp[i]);
    }
    return ans;
  }
  // Challenge code - ENDED
  void runBestTeamScore(std::vector<int> scores, std::vector<int> ages, int expected)
  {
    resultValidation(bestTeamScore(scores, ages), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runBestTeamScore({1, 3, 5, 10, 15}, {1, 2, 3, 4, 5}, 34);
  solution.runBestTeamScore({4, 5, 6, 5}, {2, 1, 2, 1}, 16);
  return 0;
}