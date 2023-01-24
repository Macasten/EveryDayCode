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
    std::cout << "!! 909. Snakes and Ladders !!\n";
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
  int snakesAndLadders(std::vector<std::vector<int>> &board)
  {
    int n = board.size();
    std::vector<std::pair<int, int>> cells(n * n + 1);
    int label = 1;
    std::vector<int> columns(n);
    iota(columns.begin(), columns.end(), 0);
    for (int row = n - 1; row >= 0; row--)
    {
      for (int column : columns)
      {
        cells[label++] = {row, column};
      }
      std::reverse(columns.begin(), columns.end());
    }
    std::vector<int> dist(n * n + 1, -1);
    std::queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      for (int next = curr + 1; next <= std::min(curr + 6, n * n); next++)
      {
        auto row = cells[next].first;
        auto column = cells[next].second;
        int destination = board[row][column] != -1 ? board[row][column] : next;
        if (dist[destination] == -1)
        {
          dist[destination] = dist[curr] + 1;
          q.push(destination);
        }
      }
    }
    return dist[n * n];
  }
  // Challenge code - ENDED
  void runSnakesAndLadders(std::vector<std::vector<int>> board, int expected)
  {
    startTest();
    resultValidation(snakesAndLadders(board), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runSnakesAndLadders(
      {{-1, -1, -1, -1, -1, -1},
       {-1, -1, -1, -1, -1, -1},
       {-1, -1, -1, -1, -1, -1},
       {-1, 35, -1, -1, 13, -1},
       {-1, -1, -1, -1, -1, -1},
       {-1, 15, -1, -1, -1, -1}},
      4);
  return 0;
}