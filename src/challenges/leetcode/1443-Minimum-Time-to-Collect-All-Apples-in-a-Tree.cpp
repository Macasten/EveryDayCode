#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

class Solution {
public:
  std::vector<std::vector<int>> adjList;
  int dfs(std::vector<bool>& hasApple,int node,int d,int prev)
  {
    int result=0,temp;
    for(int &i:adjList[node])
      if(i!=prev)
      {
        temp=dfs(hasApple,i,d+1,node);
        if(temp) result+=temp-d;
      }
    return result||hasApple[node]?result+d:0; 

  } 

  int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple) 
  {
      adjList.resize(n);
      for(std::vector<int> &e:edges)
        adjList[e[0]].push_back(e[1]),adjList[e[1]].push_back(e[0]);
      return dfs(hasApple,0,0,-1)*2;
  }
};