#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

class Solution {
public:
  class Circuit
  {
  public:
    int pGas;
    int pIndex;
    Circuit* pNext;
    Circuit( int g , int i ):pGas(g), pIndex(i){}
    ~Circuit(){};
    void setNext( Circuit* next ){
      pNext = next;
    }

    bool canCompleteCircuit( int length ){
      Circuit* next = this;
      int gas{0};
      while ( length )
      {
        gas += next->pGas;
        if( gas < 0 ){ return false; }
        next = next->pNext;
        length--;
        //std::cout << "->"<< gas ;
      }
      return true;
    }

    static Circuit* build( std::vector<int>& gas, std::vector<int>& cost , int& count ){
      size_t i {0};
      Circuit* first = new Circuit( (gas.front()- cost.front()) , i );
      Circuit* prev = first;
      i++;
      count = 1;
      int tank{0};
      for (; i < gas.size() ; i++)
      {
        tank = (gas.at(i) - cost.at(i));
        if( !(prev->pGas == 0 && tank == 0)){
          prev->setNext( new Circuit( tank, i ) );
          prev = prev->pNext;
          count++;
        }
      }
      prev->setNext(first);
      return first;
    }
  };

  static int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    // if only one station return index 0
    size_t circuitLength = gas.size();
    if( circuitLength == 0 ) return 0;

    int count{0};
    Circuit* circuit = Circuit::build( gas, cost ,count );
    for (size_t i = 0; i < count ; i++)
    {
      //std::cout << " S("<< circuit->pGas <<") -> START "<< std::endl;
      if( circuit->canCompleteCircuit( count ) ) return circuit->pIndex;
      circuit = circuit->pNext;
    }
    return -1;
  }
};

int main(){

  std::cout << "!!134. Gas Station!!" << std::endl;
  // Solution Start

  // Arrange
  std::vector<int> gas = {1,2,3,4,5};
  std::vector<int> cost = {1,2,3,4,5};

  // Assert
  std::cout << Solution::canCompleteCircuit(gas, cost) << std::endl;

  // Solution Ended
  return 0;
}