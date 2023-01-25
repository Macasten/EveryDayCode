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
    std::cout << "!! 2359. Find Closest Node to Given Two Nodes !!\n";
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
  void dfs(int node, std::vector<int> &edges, std::vector<int> &distance, std::vector<bool> &visited)
  {
    visited[node] = true;
    int neighbor = edges[node];
    if (neighbor != -1 && visited[neighbor] == false)
    {
      distance[neighbor] = distance[node] + 1;
      dfs(neighbor, edges, distance, visited);
    }
  }
  // we are using DFS to solve this problem
  int closestMeetingNode(std::vector<int> &edges, int node1, int node2)
  {
    int n = edges.size();
    int ans = -1;
    int minDist = INT_MAX;
    // dist1 store the distance from node1 to all the neighbour nodes and dist2 store the distance from node2 to all the neighbour nodes
    std::vector<int> dist1(n, 0), dist2(n, 0);
    // visited array helps us to identify wheather we visited to particular node form node1 or not similarly for visited2
    std::vector<bool> visited1(n, false), visited2(n, false);
    // calling dfs from both the nodes i.e. node1 and node2
    dfs(node1, edges, dist1, visited1);
    dfs(node2, edges, dist2, visited2);

    for (int currNode = 0; currNode < n; currNode++)
    {
      if (visited1[currNode] == true && visited2[currNode] == true && minDist > std::max(dist1[currNode], dist2[currNode]))
      {
        minDist = std::max(dist1[currNode], dist2[currNode]);
        ans = currNode;
      }
    }
    return ans;
  }
  // Challenge code - ENDED
  void runClosestMeetingNode(std::vector<int> edges, int node1, int node2, int expected)
  {
    resultValidation(closestMeetingNode(edges, node1, node2), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  solution.runClosestMeetingNode({2, 2, 3, -1}, 0, 2, 2);
  return 0;
}