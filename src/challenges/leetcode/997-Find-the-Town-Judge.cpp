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
    std::cout << "!! 997. Find the Town Judge !!\n";
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
  int findJudge(int n, std::vector<std::vector<int>> &trust)
  {
    if (trust.size() == 0 && n == 1)
      return 1;
    std::vector<int> count(n + 1);
    for (auto person : trust)
    {
      // count[person[0]]--; decrements the trust count of the first person in the pair. This is done because if the first person trusts the second person, it means that the first person does not trust themselves.
      count[person[0]]--;
      // count[person[1]]++; increments the trust count of the second person in the pair. This is done because if the first person trusts the second person, it means that the second person is trusted by the first person.
      count[person[1]]++;
    }

    for (int person = 0; person < count.size(); person++)
    {
      // check if there is a person who is trusted by everyone except themselves (n-1 people) and if such person exists it returns the index of that person.
      if (count[person] == n - 1)
        return person;
    }
    return -1;
  }
  // Challenge code - ENDED
  void runFindJudge(int n, std::vector<std::vector<int>> trust, int expected)
  {
    startTest();
    std::cout << findJudge(n, trust) << std::endl;
    resultValidation(findJudge(n, trust), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runFindJudge(2, {{1, 2}}, 2);
  solution.runFindJudge(3, {{1, 3}, {2, 3}}, 3);
  solution.runFindJudge(3, {{1, 3}, {2, 3}, {3, 1}}, -1);
  solution.runFindJudge(3, {{1, 2}, {2, 3}}, -1);
  return 0;
}