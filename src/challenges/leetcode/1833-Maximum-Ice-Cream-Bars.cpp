#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

class Solution {
public:
  static int maxIceCream(std::vector<int>& costs, int coins) {
    // sort cost
    std::sort(costs.begin(), costs.end());

    // Count chocolate bars
    int output{0};
    for(const auto& c : costs){
      if(c > coins) break;
      coins -= c;
      output++;
    }
    return output;
  }
};

int main(){

  std::cout << "!!Playground!!" << std::endl;
  // Playground Start

  // Arrange
  std::vector<std::pair<int,std::vector<int>>> test = {
    {7, {1, 3, 2, 4, 1}},
    {5, {10, 6, 8, 7, 7, 8}},
    {20, {1, 6, 3, 4, 2, 5}}
  };

  // Assert
  for(auto& t: test){
    std::cout << Solution::maxIceCream(t.second, t.first) << std::endl;
  }

  // Playground Ended
  return 0;
}