#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility> 

class Solution {
public:
  static int findMinArrowShots(std::vector<std::vector<int>>& points) {
    std::vector<std::pair<int,int>> k;
    for(int i=0;i<points.size();i++)
    {
      k.push_back({points[i][0],points[i][1]});
    }
    int cnt=1;
    std::sort(k.begin(),k.end());
    int end=k[0].second;

    for(int i=1;i<k.size();i++)
    {
      if(k[i].first>end)
      {
        cnt++;
        end=k[i].second;
      }
      end=std::min(end,k[i].second);
    }
    return cnt;
  }
};

int main(){
  std::vector<std::vector<int>> test = {
    {10,16},{2,8},{1,6},{7,12}
  };
  std::cout << Solution::findMinArrowShots(test) << std::endl;

  return 0;
}