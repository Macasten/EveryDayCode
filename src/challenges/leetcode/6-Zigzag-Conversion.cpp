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
    std::cout << "!! 6. Zigzag Conversion !!\n";
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
  std::string convert(std::string s, int numRows)
  {
    if (s.length() < 2 || numRows == 1)
      return s;

    int columns = std::ceil(s.length() / numRows);
    std::vector<std::string> lines(numRows, "");
    numRows--;
    bool down{true};
    int rowIndex{-1};
    for (const auto l : s)
    {
      if (down)
      {
        rowIndex++;
        if (rowIndex == numRows)
          down = false;
      }
      else
      {
        rowIndex--;
        if (rowIndex == 0)
          down = true;
      }
      lines.at(rowIndex) += l;
    }

    for (int i = 1; i <= numRows; i++)
    {
      lines.at(0).append(lines.at(i));
    }
    return lines.front();
  }

  // Challenge code - ENDED
  void runConvert(std::string s, int numRows, std::string expected)
  {
    startTest();
    std::cout << convert(s, numRows) << std::endl;
    std::cout << expected << std::endl;
    resultValidation(convert(s, numRows), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runConvert("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
  solution.runConvert("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
  solution.runConvert("A", 4, "A");
  return 0;
}