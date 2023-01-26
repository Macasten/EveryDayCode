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
    std::cout << "!! 787. Cheapest Flights Within K Stops !!\n";
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
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k)
  {
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (auto flight : flights)
    {
      // flight[0] represent node i, flight[1] represent neighbor node of node i, flight[2] represent cost between node i to neighbor node
      adj[flight[0]].push_back({flight[1], flight[2]});
    }
    // it will store [node, cost]
    std::queue<std::pair<int, int>> q;
    q.push({src, 0});
    // it will store minimum cost to reach each node
    std::vector<int> minCost(n, std::numeric_limits<int>::max());
    int stops = 0;
    while (!q.empty() && stops <= k)
    {
      int size = q.size();
      while (size--)
      {
        auto [currNode, cost] = q.front();
        q.pop();
        for (auto &[neighbour, price] : adj[currNode])
        {
          if (price + cost < minCost[neighbour])
          {
            minCost[neighbour] = price + cost;
            q.push({neighbour, minCost[neighbour]});
          }
        }
      }
      stops++;
    }
    if (minCost[dst] == std::numeric_limits<int>::min())
      return -1;
    return minCost[dst];
  }
  // Challenge code - ENDED
  void run()
  {
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  return 0;
}