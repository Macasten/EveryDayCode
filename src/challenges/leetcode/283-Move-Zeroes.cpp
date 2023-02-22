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
    std::cout << "!! 283. Move Zeroes !!\n";
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
  void moveZeroes(std::vector<int> &nums)
  {
    size_t size{nums.size()};
    nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
    print_vector(nums);
    size -= nums.size();
    while (size)
    {
      nums.push_back(0);
      size--;
    }
  }
  // Challenge code - ENDED
  void runMoveZeroes(std::vector<int> nums, std::vector<int> expected)
  {
    moveZeroes(nums);
    resultValidation(nums, expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();

  solution.runMoveZeroes({0, 1, 0, 3, 12}, {1, 3, 12, 0, 0});
  return 0;
}