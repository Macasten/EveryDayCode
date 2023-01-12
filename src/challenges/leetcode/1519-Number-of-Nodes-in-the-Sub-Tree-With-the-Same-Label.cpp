////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

////////////////////////////////////////////////////////////////////////////////
// Personal Helpers
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Solution
////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
  static void ShowChallengeTitle(){
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "!! 1519. Number of Nodes in the Sub-Tree With the Same Label !!\n";
    std::cout << "-------------------------------------------------------------\n";
  }
  // Challenge code - START
  std::vector<int> array;

  std::vector<int> countSubTrees(int n, std::vector<std::vector<int>>& edges, std::string labels) {
    array.resize(n); //output array
    
    //creating adjacency list
    std::vector<std::vector<int>> a(n);
    for(auto x:edges){
        a[x[0]].push_back(x[1]);
        a[x[1]].push_back(x[0]);
    }
    dfs(-1,0,a,labels);
    return array;

  }

  std::vector<int> dfs(int prev,int curr,std::vector<std::vector<int>>& a, std::string& labels)
  {
    std::vector<int> ans(26);
    for(auto x:a[curr]) {
      if(prev!=x) {
      // array return by the children node
        std::vector<int> res = dfs(curr,x,a,labels); 
      // combining the frequencies of left and right subtrees into one array
        for(int i=0;i<26;i++) 
            ans[i]+=res[i];
      }
    }
    // incrementing the freq of curr node label and storing in output array
    array[curr] = ++ans[labels[curr]-'a'];
    return ans;
  }
  // Challenge code - ENDED
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main(){
  Solution::ShowChallengeTitle();
  return 0;
}