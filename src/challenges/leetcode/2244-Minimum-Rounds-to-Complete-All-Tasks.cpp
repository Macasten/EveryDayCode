#include <iostream>
#include <map>
#include <vector>


void showMap( std::map<int,uint> m){
  std::cout << "Map:" << std::endl;
  for(auto it = m.begin(); it != m.end(); ++it){
    std::cout << it->first << " : " << it->second << std::endl;
  }
}
class Solution {
public:

  static inline int minimumRoundsNumber(uint count){
    if(count == 1) return -1;
    return ((int)(count/3) + ( count%3 == 0 ? 0 : 1 ));
  }

  static int minimumRounds(std::vector<int>& tasks) {
    // Initialize map
    std::map<int,uint> tasksMap;
    for(const auto& t : tasks){
      tasksMap[t]++;
    }

    // Remove
    showMap(tasksMap);
    int output{0};
    for(auto it=tasksMap.begin(); it != tasksMap.end(); ++it){
      int aux = minimumRoundsNumber(it->second);
      if (aux < 0 ) return -1;
      output += aux;
    }
    return output;
  }
};

int main(){

  std::vector<int> test = {2,3,3};
  std::cout << Solution::minimumRounds(test) << std::endl;
  return 0;
}