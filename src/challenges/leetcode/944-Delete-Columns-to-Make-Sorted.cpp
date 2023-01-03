#include <iostream>
#include <map>
#include <vector>



class Solution {
public:
  static int minDeletionSize(std::vector<std::string>& strs){
    if(strs.size() == 1 ) return 0;

    // Map initialization
    std::map<int,char> columns;
    
    int aux{0};
    for(const auto &letter: strs.at(0)){
      columns[aux] = letter;
      aux++;
    }

    // Find columns to remove
    std::vector<int> index;
    for(const auto &word: strs){
      // std::cout << word << std::endl;
      // Find columns
      for(auto itr = columns.begin(); itr != columns.end(); ++itr){
        std::cout << itr->second << std::endl;
        if(itr->second > word.at(itr->first)){
          index.push_back(itr->first);
        }
        itr->second = word.at(itr->first);
      }

      // Erase columns
      if(index.size() > 0){
        for(const auto &ind : index) columns.erase(ind);
        index.clear();
      }
      if(columns.size() == 0) return word.size();
    }

    return strs.at(0).size()-columns.size();

  }
};

int main()
{
  std::vector<std::string> test {
    "rrjk","furt","guzm"
  };

  std::cout << Solution::minDeletionSize(test) << std::endl;
  return 0;
}