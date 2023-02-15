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
    std::cout << "!! 989. Add to Array-Form of Integer !!\n";
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
  std::vector<int> addToArrayForm_First(std::vector<int> &num, int k)
  {
    int rest{0};
    int aux{0};
    for (auto it = num.rbegin(); it != num.rend(); ++it)
    {
      rest = k % 10;
      k /= 10;
      aux = *it + rest;
      if (aux > 9)
      {
        aux %= 10;
        k++;
      }
      *it = aux;

      if (k == 0)
        break;
    }
    while (k)
    {
      rest = k % 10;
      k /= 10;
      num.insert(num.begin(), rest);
    }

    return num;
  }

  std::vector<int> addToArrayForm(std::vector<int> &num, int k)
  {
    int rest{0};
    int aux{0};
    auto it = num.rbegin();
    while (k)
    {
      rest = k % 10;
      k /= 10;
      aux = *it + rest;

      if (aux > 9)
      {
        aux %= 10;
        k++;
      }

      if (it == num.rend())
      {
        num.insert(num.begin(), aux);
        it = num.rend();
      }
      else
      {
        *it = aux;
        ++it;
      }
    }

    return num;
  }
  // Challenge code - ENDED
  void runAddToArrayForm(std::vector<int> num, int k, std::vector<int> expected)
  {
    resultValidation(addToArrayForm(num, k), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();

  solution.runAddToArrayForm({1, 2, 0, 0}, 34, {1, 2, 3, 4});
  solution.runAddToArrayForm({2, 7, 4}, 181, {4, 5, 5});
  solution.runAddToArrayForm({2, 1, 5}, 806, {1, 0, 2, 1});
  solution.runAddToArrayForm({2, 1, 5}, 100000, {1, 0, 0, 2, 1, 5});
  return 0;
}